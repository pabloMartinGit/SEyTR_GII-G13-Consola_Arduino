import os
import tkinter as tk
from tkinter import filedialog
from tkinter import messagebox
import serial.tools.list_ports

class ArduinoCompilerApp:
    def __init__(self, master):
        self.master = master
        self.master.title("Arduino Game Selector")

        self.port_label = tk.Label(self.master, text="Selecciona el puerto:")
        self.port_label.pack()

        self.port_var = tk.StringVar()
        available_ports = self.get_available_ports()
        if not available_ports:
            available_ports = ["No ports available"]
        self.port_dropdown = tk.OptionMenu(self.master, self.port_var, *available_ports)
        self.port_dropdown.pack(pady=10)

        self.select_button = tk.Button(self.master, text="Seleccionar Juego", command=self.select_hex)
        self.select_button.pack(pady=10)

        self.play_button = tk.Button(self.master, text="Jugar", command=self.play_game, state="disabled")
        self.play_button.pack(pady=10)

        self.names_label = tk.Label(self.master, text="Pablo Martín, Javier Rubia, Aitor Martín", font=("Comic Sans MS", 14), fg="red")
        self.names_label.pack(pady=10)

        self.logo_image = tk.PhotoImage(file="logo_uni.png")
        self.logo_image = self.logo_image.subsample(2)  # Reduce el tamaño de la imagen a la mitad
        self.logo_label = tk.Label(self.master, image=self.logo_image)
        self.logo_label.pack(pady=10)

        self.selected_hex = ""

    def select_hex(self):
        self.selected_hex = filedialog.askopenfilename(filetypes=[("Hex Files", "*.hex")])
        if self.selected_hex:
            self.play_button.config(state="normal")

    def play_game(self):
        if self.selected_hex:
            port = self.port_var.get()
            if port:
                upload_command = f"arduino-cli upload --fqbn arduino:avr:nano --port {port} --input-file {self.selected_hex}"
                os.system(upload_command)
                messagebox.showinfo("Carga Exitosa", "El archivo .hex ha sido cargado correctamente.")
            else:
                messagebox.showerror("Error", "Por favor, selecciona un puerto antes de cargar.")

    def get_available_ports(self):
        ports = serial.tools.list_ports.comports()
        return [port.device for port in ports]

def main():
    root = tk.Tk()
    app = ArduinoCompilerApp(root)
    root.mainloop()

if __name__ == "__main__":
    main()
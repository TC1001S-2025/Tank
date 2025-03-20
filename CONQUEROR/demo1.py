from RobotController import RobotController

robot = RobotController()


robot.move_forward()  # Mueve adelante 5s con potencia 150
robot.turn_left()     # Gira a la izquierda
robot.stop()            # Se detiene

robot.sketch_manager.finalize_sketch()  # Finaliza y guarda el código
robot.upload_sketch()                    # Compila y sube el código a Arduino
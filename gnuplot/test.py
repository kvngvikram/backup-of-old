import os
import subprocess

subprocess.Popen("gnuplot",shell=True)
subprocess.Popen("set terminal dumb",shell=True)
subprocess.Popen("plot sin(x)",shell=True)

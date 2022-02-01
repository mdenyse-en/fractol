# Fractol


>School21 project, but it was modified after defence (added threads). Now it don't meet the NORM.

The aim of that project is visualisation of Mandelbrot fractal. And also some another fractals.
For window management used MiniLibX library (/mlx).

## Running program:

**Must be at least one** parameter - number, that means what type of fractals need to enabled:
- **1** - Mandelbrot
- **2** - Julia
- **3** - Newton's pool
- **4** - Maldebar
- **5** - Burning ship
- **6** - Celtic Maldebrot

Another parameters (optional,** [parameter][value]**):
- **x*** - WIDTH of window (**x800** - whith that parameter width of created window will be set at 800px. Can be from 400 to 2000px).
- **y*** - HEIGHT of window (**y800** - whith that parameter height of created window will be set at 800px. Can be from 400 to 2000px).
- **w***  - WIDTH of enabled area (double value).
- **i*** - COUNT of iterations (int value, **i20** - minimum).
- **px*** - coordinate X of center enabled area (double value).
- **py*** - coordinate Y of center enabled area (double value).
- **cx*** - coordinate X of center Julia's fractal (double value).
- **cy*** - coordinate Y of center Julia's fractal (double value).

##### Sampes of running program:

`./fractol 1`

`./fractol 2 x780 px1.2 w3.1`

`./fractol x780 px1.2 w3.1` **- wrong!** (but if running by that, you recive a hint with list of needed parameters)


### There is a description of main window:

>![Main window](https://github.com/mdenyse-en/screenshots/blob/master/fractol-interface_information_min1.png)

### Control buttons:
- **1**,**2**,**3**,**4**,**5**,**6** - Display another type of fractal
- **+** - Zoom in
- **-** - Zoom out
- **,** -Reduce count of iterations
- **.** - Increase count of iterations
- **[**, **]** - Change real digit (only for Julia fractal)
- **'**, **\\** - Change imagine digit (only for Julia fractal)
- **R** - Increase count of iterations
- **Mouse will (Scroll)** - Zoom (on mouse position)
- **Mouse will (Press)** - Move by mouse (press again to cancel)
- **Mouse left button** - Center on cursor position
- **Arrows** - Move left, right, up, down
- **9**, **0** - Change gradient
- **C** - (On/Off) changing count of iteration when zooming
- **H** - Show help

> Also you can see that controls, when program are runned by press "H".

Actualy, gradients, that using in that program don't show how beautiful fractals can be. Because that gradients are linear. But, some of them can be a little bit attractive:

![Julia](https://github.com/mdenyse-en/screenshots/blob/master/fractol_sample_julia.png)
![Maldebrot](https://github.com/mdenyse-en/screenshots/blob/master/fractol_sample_maldebrot.png)

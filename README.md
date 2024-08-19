# MAX_WPASupplicant
Handoff algorithms for for Wpa Supplicant v2.1
The implemented algorithms are:
- WPA (original)
- EWMA (with alpha parameter)
- WPA_EWMA (with alpha parameter)
- MAX (with Ws parameter or window size)
- WPA_MAX (with Ws parameter)
- EWMAX (formerly called EWMA_MAX) (with alpha and Ws parameters)
- HM (with parameter hm or fixed hysteresis margin)

The handoff algorithm and parameters can be defined in the command line. The parameters are:
- x: algorithm name
- X: Ws
- y: alpha
- Y: hysteresis margin

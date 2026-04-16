/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> multimac_154_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t multimac_154_init(void)

{
  mac_device *dev;
  int *piVar1;
  int iVar2;
  
  if (s_devices == (mac_device *)0x0) {
    piVar1 = (int *)mm_calloc(1,0xa8);
    s_device_nr = '\x01';
    dev = (mac_device *)(piVar1 + 2);
    piVar1[1] = (int)&s_mac_154_ops;
    *piVar1 = (int)dev;
    s_devices = dev;
    random_init();
    mac_pal_init();
    mac_reset_pib(dev);
    mac_reset_ctx(dev);
    mac_pal_enable();
    iVar2 = nwk_mm_register_interface(piVar1,*piVar1 + 0x2c);
    if (iVar2 != 0) {
      __assert_func(0,0,0,0);
    }
  }
  return 0;
}


/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> multimac_154_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: config */
/* WARNING: Unknown calling convention */

ezb_err_t multimac_154_init(void)

{
  mac_device *dev;
  int *piVar1;
  int iVar2;
  int *piStack_18;
  nwk_mac_iface_config_t config;
  
  if (s_devices == (mac_device *)0x0) {
    piVar1 = (int *)mm_calloc(1,0xa8);
    s_device_nr = '\x01';
    config.iface = (mac_interface_t *)0x3;
    dev = (mac_device *)(piVar1 + 2);
    piVar1[1] = (int)&s_mac_154_ops;
    *piVar1 = (int)dev;
    s_devices = dev;
    piStack_18 = piVar1;
    random_init();
    mac_pal_init();
    mac_reset_pib(dev);
    mac_reset_ctx(dev);
    mac_pal_enable();
    iVar2 = nwk_mm_register_interface(&piStack_18,*piVar1 + 0x2c);
    if (iVar2 != 0) {
      __assert_func(0,0,0,0);
    }
  }
  return 0;
}


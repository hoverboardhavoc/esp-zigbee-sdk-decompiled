/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> multimac_154_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Variable defined which should be unmapped: config */
/* WARNING: Unknown calling convention */

ezb_err_t multimac_154_init(void)

{
  bool bVar1;
  mac_device *dev;
  int *piVar2;
  int iVar3;
  int *piStack_18;
  nwk_mac_iface_config_t config;
  
  if (s_devices == (mac_device *)0x0) {
    piVar2 = (int *)mm_calloc(1,0xa8);
    s_devices = (mac_device *)(piVar2 + 2);
    s_device_nr = '\x01';
    config.iface = (mac_interface_t *)0x3;
    bVar1 = false;
    while (dev = s_devices, !bVar1) {
      *piVar2 = (int)s_devices;
      piVar2[1] = (int)&s_mac_154_ops;
      piStack_18 = piVar2;
      mac_init(dev);
      iVar3 = nwk_mm_register_interface(&piStack_18,*piVar2 + 0x2c);
      if (iVar3 != 0) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x734,
                      "(nwk_mm_register_interface(&config, &((struct mac_device *)((&ifaces[i])->dev))->ctx.iface_id)) == 0"
                     );
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      bVar1 = true;
    }
  }
  return 0;
}


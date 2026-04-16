/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> multimac_154_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

ezb_err_t multimac_154_init(void)

{
  bool bVar1;
  mac_device *dev;
  int *piVar2;
  int iVar3;
  
  if (s_devices == (mac_device *)0x0) {
    piVar2 = (int *)mm_calloc(1,0xa8);
    s_devices = (mac_device *)(piVar2 + 2);
    s_device_nr = '\x01';
    bVar1 = false;
    while (dev = s_devices, !bVar1) {
      *piVar2 = (int)s_devices;
      piVar2[1] = (int)&s_mac_154_ops;
      mac_init(dev);
      iVar3 = nwk_mm_register_interface(piVar2,*piVar2 + 0x2c);
      if (iVar3 != 0) {
        __assert_func("//build/esp-zigbee/src/core/mac/mac.c",0x70c,"multimac_154_init",
                      "(nwk_mm_register_interface(&ifaces[i], &((struct mac_device *)((&ifaces[i])->dev))->ctx.iface_id)) == 0"
                     );
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      bVar1 = true;
    }
  }
  return 0;
}


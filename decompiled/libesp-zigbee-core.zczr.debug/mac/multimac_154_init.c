/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> multimac_154_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 multimac_154_init(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int *piStack_18;
  undefined4 uStack_14;
  
  if (s_devices == (int *)0x0) {
    piVar2 = (int *)mm_calloc(1,0xa8);
    s_devices = piVar2 + 2;
    s_device_nr = 1;
    uStack_14 = 3;
    bVar1 = false;
    while (!bVar1) {
      *piVar2 = (int)s_devices;
      piVar2[1] = (int)s_mac_154_ops;
      piStack_18 = piVar2;
      mac_init();
      iVar3 = nwk_mm_register_interface(&piStack_18,*piVar2 + 0x2c);
      if (iVar3 != 0) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x785,
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


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> multimac_154_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 multimac_154_init(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piStack_18;
  undefined4 uStack_14;
  
  if (s_devices == (int *)0x0) {
    piVar2 = (int *)mm_calloc(1,0xa8);
    s_device_nr = 1;
    uStack_14 = 3;
    piVar1 = piVar2 + 2;
    piVar2[1] = (int)s_mac_154_ops;
    *piVar2 = (int)piVar1;
    s_devices = piVar1;
    piStack_18 = piVar2;
    random_init();
    mac_pal_init();
    mac_reset_pib(piVar1);
    mac_reset_ctx(piVar1);
    mac_pal_enable();
    iVar3 = nwk_mm_register_interface(&piStack_18,*piVar2 + 0x2c);
    if (iVar3 != 0) {
      __assert_func(0,0,0,0);
    }
  }
  return 0;
}


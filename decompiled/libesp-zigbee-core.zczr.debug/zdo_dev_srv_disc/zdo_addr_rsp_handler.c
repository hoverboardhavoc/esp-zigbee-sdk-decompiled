/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_addr_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_addr_rsp_handler(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined2 auStack_12 [5];
  
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  iStack_18 = 0;
  if (param_1 == 0) {
_L0:
    uVar2 = 0xfe;
  }
  else {
    if (*(int *)(param_1 + 0x14) == 0) {
      uVar2 = 0xfe;
      goto _L0;
    }
    if (*(short *)(param_1 + 6) == -0x8000) {
      iVar1 = zdo_op_nwk_addr_rsp(2,&uStack_28,0);
      if (iVar1 != 0) {
        uVar2 = 0xfe;
        goto _L0;
      }
    }
    else {
      if (*(short *)(param_1 + 6) != -0x7fff) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x1dc,
                      "zdo_addr_rsp_handler",&_LC5);
        goto _L0;
      }
      iVar1 = zdo_op_ieee_addr_rsp(2,&uStack_28,0);
      if (iVar1 != 0) {
        uVar2 = 0xfe;
        goto _L0;
      }
    }
    auStack_12[0] = 0;
    nwk_address_update((int)&uStack_28 + 1,uStack_20 >> 0x10,auStack_12);
    uVar2 = zdo_cb_address_rsp(&uStack_28,param_1 + 8);
  }
_L0:
  if (iStack_18 != 0) {
    mm_free();
  }
  return uVar2;
}


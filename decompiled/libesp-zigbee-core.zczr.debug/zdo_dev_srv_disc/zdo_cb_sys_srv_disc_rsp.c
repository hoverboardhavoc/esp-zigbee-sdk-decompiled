/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_cb_sys_srv_disc_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_cb_sys_srv_disc_rsp(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint auStack_24 [3];
  
  if ((param_1 != 0) && (param_2 != 0)) {
    zdo_packet_notify_result(param_2,0);
    return 0;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x6b7,
                        "zdo_cb_sys_srv_disc_rsp","rsp && ctx");
  auStack_24[0] = 0;
  if (iVar1 == 0) {
    uVar3 = 0xfe;
  }
  else if (*(int *)(iVar1 + 0x14) == 0) {
    uVar3 = 0xfe;
  }
  else {
    iVar2 = zdo_op_sys_srv_disc_rsp(auStack_24,0);
    if (iVar2 == 0) {
      if ((auStack_24[0] & 0x400000) != 0) {
        iVar2 = core_globals_get();
        *(undefined2 *)(iVar2 + 0x9dc) = *(undefined2 *)(iVar1 + 4);
      }
      uVar3 = zdo_cb_sys_srv_disc_rsp(auStack_24,iVar1 + 8);
    }
    else {
      uVar3 = 0xfe;
    }
  }
  return uVar3;
}


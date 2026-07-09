/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_sys_srv_disc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_sys_srv_disc_req_handler(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_18 [2];
  ushort uStack_16;
  ushort auStack_14 [4];
  
  auStack_14[0] = 0;
  auStack_18[0] = 0;
  uStack_16 = 0;
  if (param_1 == 0) {
    uVar2 = 0xfe;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    uVar2 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar2 = 0xfe;
  }
  else {
    iVar1 = zdo_op_sys_srv_disc_req(auStack_14,0);
    if (iVar1 == 0) {
      iVar1 = af_get_node_desc();
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uStack_16 = *(ushort *)(iVar1 + 10) & auStack_14[0] & 0x1ff;
        if (*(ushort *)(iVar1 + 10) >> 9 == auStack_14[0] >> 9) {
          uStack_16 = uStack_16 | auStack_14[0] & 0xfe00;
        }
        if (uStack_16 == 0) {
          uVar2 = 0xfe;
        }
        else {
          uVar2 = zdo_op_sys_srv_disc_rsp(*(undefined4 *)(param_2 + 0x14),auStack_18,1);
        }
      }
    }
    else {
      uVar2 = 0xfe;
    }
  }
  return uVar2;
}


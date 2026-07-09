/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_handle_received_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_handle_received_msg(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 local_20;
  undefined2 uStack_1e;
  uint uStack_1c;
  int iStack_18;
  ushort auStack_12 [3];
  
  zmsg_read_bytes(0,2,auStack_12);
  if ((auStack_12[0] & 3) == 0) {
    iVar2 = nwk_is_joined();
    if (iVar2 != 0) {
      iStack_18 = 0;
      _local_20 = CONCAT22(*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 6));
      uStack_1c = (uint)*(ushort *)(param_2 + 9);
      uVar1 = zmsg_get_offset(param_1);
      zmsg_remove_header(param_1,uVar1);
      iStack_18 = param_1;
      nwk_nlde_data_indication(&local_20);
      return 0;
    }
    uVar1 = 3;
  }
  else {
    if ((auStack_12[0] & 3) == 1) {
      nwk_handle_received_cmd(param_1,param_2);
      return 0;
    }
    uVar1 = 0x10;
  }
  if (param_1 != 0) {
    zmsg_free(param_1);
  }
  return uVar1;
}


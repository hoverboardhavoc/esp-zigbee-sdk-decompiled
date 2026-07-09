/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_bind_mgmt.o -> zdo_bind_mgmt_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_bind_mgmt_rsp_handler(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_14 [2];
  ushort uStack_12;
  
  if (param_1 == 0) {
    return 0x80;
  }
  uVar1 = 0x84;
  if (*(ushort *)(param_1 + 6) - 0x8021 < 2) {
    iVar3 = *(int *)(param_1 + 0x14);
    auStack_14[0] = 0;
    if (iVar3 != 0) {
      uStack_12 = 0;
      uVar2 = zmsg_get_length(iVar3);
      af_read_le8_isra_0(iVar3,&uStack_12,auStack_14);
      if (uStack_12 <= uVar2) {
        zdo_packet_notify_result(param_1 + 8,0,auStack_14);
        return 0;
      }
    }
    uVar1 = 0xfe;
  }
  return uVar1;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> apsme_switch_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int apsme_switch_key_request(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 2;
  if (param_1 != (uint *)0x0) {
    uVar1 = *param_1;
    uVar2 = param_1[1];
    iVar5 = 2;
    if (uVar1 != 0 || uVar2 != 0) {
      if ((uVar1 != 0xffffffff) || (uVar3 = 0x27, uVar2 != 0xffffffff)) {
        uVar3 = 0x2f;
      }
      iVar4 = zmsg_alloc(uVar3);
      iVar5 = 1;
      if (iVar4 != 0) {
        aps_frame_append_cmd_hdr((uVar1 & uVar2) == 0xffffffff,(uVar1 & uVar2) != 0xffffffff,0,0);
        zmsg_append_u8_isra_0(iVar4,9);
        zmsg_append_u8_isra_0(iVar4,(char)param_1[2]);
        iVar5 = aps_send_cmd(iVar4,param_1);
        if (iVar5 != 0) {
          zmsg_free(iVar4);
        }
      }
    }
  }
  return iVar5;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> aps_send_cmd_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_send_cmd_confirm(int param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  char cStack_3d;
  uint uStack_3c;
  uint uStack_38;
  char cStack_34;
  undefined1 auStack_33 [15];
  uint uStack_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  byte bStack_14;
  
  cStack_3d = '\0';
  uVar2 = zmsg_get_offset();
  zmsg_read_bytes(param_1,uVar2,1,&cStack_3d);
  if ((cStack_3d == '\x05') && (param_2 == 0)) {
    sVar1 = zmsg_get_offset(param_1);
    zmsg_read_bytes(param_1,sVar1 + 1,0x22,&cStack_34);
    if (cStack_34 == '\x04') {
      uStack_3c = uStack_20 << 0x18 | uStack_24 >> 8;
      uStack_38 = uStack_20 >> 8 | uStack_1c << 0x18;
      puVar3 = (uint *)nwk_get_extended_address();
      if ((((uStack_18 << 0x18 | uStack_1c >> 8) == *puVar3) &&
          (((uint)bStack_14 << 0x18 | uStack_18 >> 8) == puVar3[1])) &&
         (iVar4 = aps_secur_get_key_pair_by_addr(&uStack_3c), iVar4 != 0)) {
        aps_secur_key_pair_set_unverified(auStack_33);
      }
    }
  }
  if (param_1 != 0) {
    zmsg_free(param_1);
  }
  return;
}


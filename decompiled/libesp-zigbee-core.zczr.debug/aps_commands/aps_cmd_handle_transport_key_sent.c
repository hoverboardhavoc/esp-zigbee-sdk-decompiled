/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_transport_key_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_cmd_handle_transport_key_sent(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  uint *puVar4;
  int iVar5;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  char cStack_34;
  undefined1 auStack_33 [15];
  uint uStack_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  byte bStack_14;
  
  if (param_2 == 0) {
    sVar3 = zmsg_get_offset();
    zmsg_read_bytes(param_1,sVar3 + 1,0x22,&cStack_34);
    if (cStack_34 == '\x04') {
      uStack_44 = uStack_20 << 0x18 | uStack_24 >> 8;
      uStack_40 = uStack_20 >> 8 | uStack_1c << 0x18;
      uVar2 = uStack_18 << 0x18 | uStack_1c >> 8;
      uVar1 = (uint)bStack_14 << 0x18 | uStack_18 >> 8;
      uStack_3c = uVar2;
      uStack_38 = uVar1;
      puVar4 = (uint *)nwk_get_extended_address();
      if (((uVar2 == *puVar4) && (uVar1 == puVar4[1])) &&
         (iVar5 = aps_secur_get_key_pair_by_addr(&uStack_44), iVar5 != 0)) {
        aps_secur_key_pair_set_unverified(auStack_33);
      }
    }
  }
  return;
}


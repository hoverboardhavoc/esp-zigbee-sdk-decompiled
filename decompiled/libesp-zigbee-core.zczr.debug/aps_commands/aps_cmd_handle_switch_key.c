/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_switch_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_cmd_handle_switch_key(undefined2 *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  undefined1 auStack_24 [8];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 auStack_14 [4];
  
  iVar2 = aps_secur_is_tc();
  if (iVar2 == 0) {
    uStack_1c = 0;
    uStack_18 = 0;
    auStack_14[0] = 0;
    sVar1 = zmsg_get_offset(param_2);
    iVar2 = nwk_address_extended_by_short(*param_1,auStack_24);
    if ((iVar2 == 0) && (iVar2 = aps_secur_is_addr_tc(auStack_24), iVar2 != 0)) {
      zmsg_read_bytes(param_2,sVar1 + 1,1,auStack_14);
      apsme_switch_key_indication(&uStack_1c);
    }
  }
  if (param_2 != 0) {
    zmsg_free(param_2);
  }
  return;
}


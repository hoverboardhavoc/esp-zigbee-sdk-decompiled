/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_tunnel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_cmd_handle_tunnel(undefined2 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int local_20;
  int iStack_1c;
  undefined1 auStack_18 [8];
  
  iVar1 = aps_secur_is_tc();
  if (iVar1 == 0) {
    iVar1 = zmsg_get_offset(param_2);
    uVar2 = iVar1 + 1U & 0xffff;
    iVar1 = zmsg_get_length(param_2);
    if (((7 < (int)(iVar1 - uVar2)) &&
        (iVar1 = nwk_address_extended_by_short(*param_1,auStack_18), iVar1 == 0)) &&
       (iVar1 = aps_secur_is_addr_tc(auStack_18), iVar1 != 0)) {
      local_20 = 0;
      iStack_1c = 0;
      zmsg_read_bytes(param_2,uVar2,8,&local_20);
      if ((local_20 != 0 || iStack_1c != 0) && ((local_20 != -1 || (iStack_1c != -1)))) {
        zmsg_remove_header(param_2,0xb);
        iVar1 = aps_relay_cmd(param_2,&local_20);
        if (iVar1 == 0) {
          return;
        }
      }
    }
  }
  if (param_2 != 0) {
    zmsg_free(param_2);
  }
  return;
}


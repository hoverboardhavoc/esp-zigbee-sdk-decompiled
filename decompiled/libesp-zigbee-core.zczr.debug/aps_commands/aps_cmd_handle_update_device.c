/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_update_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_cmd_handle_update_device(undefined2 *param_1,int param_2)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar3 = aps_secur_is_tc();
  if (iVar3 != 0) {
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    iVar3 = zmsg_get_offset(param_2);
    uVar2 = iVar3 + 1U & 0xffff;
    iVar3 = zmsg_get_length(param_2);
    if (((10 < (int)(iVar3 - uVar2)) &&
        (iVar3 = nwk_address_extended_by_short(*param_1,&uStack_28), iVar3 == 0)) &&
       (((*(ushort *)(param_2 + 0x16) & 4) != 0 ||
        ((iVar3 = aps_secur_get_key_pair_by_addr(&uStack_28), iVar3 == 0 ||
         ((*(ushort *)(iVar3 + 0x34) & 1) != 0)))))) {
      iVar3 = zmsg_read_bytes(param_2,uVar2,8,&uStack_20);
      uVar2 = uVar2 + iVar3 & 0xffff;
      iVar3 = zmsg_read_bytes(param_2,uVar2,2,&uStack_18);
      zmsg_read_bytes(param_2,uVar2 + iVar3 & 0xffff,1,(int)&uStack_18 + 2);
      uVar1 = *param_1;
      iVar3 = nwk_neighbor_table_get_by_short(uVar1);
      if (iVar3 == 0) {
        iVar3 = nwk_route_table_find(uVar1);
        if (iVar3 != 0) {
          nwk_route_table_add_rev_route(uStack_18 & 0xffff,*(undefined2 *)(iVar3 + 2),0);
        }
      }
      else {
        nwk_route_table_add_rev_route(uStack_18 & 0xffff,uVar1,0);
      }
      apsme_update_device_indication(&uStack_28);
    }
  }
  if (param_2 != 0) {
    zmsg_free(param_2);
  }
  return;
}


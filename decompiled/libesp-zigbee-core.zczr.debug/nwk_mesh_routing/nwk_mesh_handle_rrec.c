/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_mesh_routing.o -> nwk_mesh_handle_rrec
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_mesh_handle_rrec(int param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  byte bStack_15;
  undefined2 uStack_14;
  byte local_11;
  
  iVar3 = nwk_is_router_started();
  if ((iVar3 != 0) &&
     (iVar3 = nwk_secur_get_seclevel(), ((*(ushort *)(param_1 + 0x16) & 2) != 0) == (iVar3 != 0))) {
    local_11 = 0;
    zmsg_move_offset(param_1,1);
    uVar4 = zmsg_get_offset(param_1);
    zmsg_read_bytes(param_1,uVar4,1,&local_11);
    zmsg_move_offset(param_1,1);
    iVar3 = zmsg_get_offset(param_1);
    uVar6 = (uint)local_11;
    uVar5 = zmsg_get_length(param_1);
    if (iVar3 + uVar6 * 2 <= uVar5) {
      uVar1 = *(ushort *)(param_2 + 4);
      uVar5 = nwk_get_short_address();
      if (uVar1 == uVar5) {
        iVar3 = core_globals_get();
        if ((*(char *)(iVar3 + 0x9f7) != '\0') &&
           (iVar3 = core_globals_get(), local_11 <= *(byte *)(iVar3 + 0x9de))) {
          if (local_11 == 0) {
            nwk_route_record_table_remove_by_dst(*(undefined2 *)(param_2 + 6));
          }
          else {
            iVar3 = nwk_route_record_table_find_or_create(*(undefined2 *)(param_2 + 6));
            if (iVar3 == 0) goto _L0;
            *(byte *)(iVar3 + 2) = local_11;
            for (local_11 = 0; local_11 < *(byte *)(iVar3 + 2); local_11 = local_11 + 1) {
              uVar4 = zmsg_get_offset(param_1);
              zmsg_read_bytes(param_1,uVar4,2,(uint)local_11 * 2 + iVar3 + 4);
              zmsg_move_offset(param_1,2);
            }
          }
          zmsg_free(param_1);
          return;
        }
      }
      else if ((*(ushort *)(param_2 + 4) < 0xfff8) &&
              (zmsg_read_bytes(param_1,6,1,&bStack_15), 1 < bStack_15)) {
        uStack_14._0_1_ = bStack_15 - 1;
        zmsg_write_bytes(param_1,6,1,&uStack_14);
        sVar2 = zmsg_get_offset(param_1);
        uStack_14 = CONCAT11(uStack_14._1_1_,local_11 + 1);
        zmsg_write_bytes(param_1,sVar2 + -1,1,&uStack_14);
        uStack_14 = nwk_get_short_address();
        zmsg_append_bytes(param_1,2,&uStack_14);
        nwk_fwd_send_msg_delayed(param_1,0);
        return;
      }
    }
  }
_L0:
  if (param_1 != 0) {
    zmsg_free(param_1);
  }
  return;
}


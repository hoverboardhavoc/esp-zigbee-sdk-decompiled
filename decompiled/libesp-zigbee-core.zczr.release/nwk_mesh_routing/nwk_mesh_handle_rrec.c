/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_handle_rrec
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: relay_count */
/* WARNING: Unknown calling convention */

void nwk_mesh_handle_rrec(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  ushort uVar1;
  _Bool _Var2;
  short sVar3;
  undefined3 extraout_var;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  byte local_14;
  byte bStack_13;
  undefined2 uStack_12;
  uint8_t relay_count;
  uint8_t radius;
  
  _Var2 = nwk_is_router_started();
  if (CONCAT31(extraout_var,_Var2) == 0) {
    if (msg == (zmsg_t *)0x0) {
      return;
    }
  }
  else {
    iVar4 = nwk_secur_get_seclevel();
    if ((ushort)(iVar4 != 0) == (msg->flags >> 1 & 1)) {
      local_14 = 0;
      zmsg_move_offset(msg,1);
      uVar5 = zmsg_get_offset(msg);
      zmsg_read_bytes(msg,uVar5,1,&local_14);
      zmsg_move_offset(msg,1);
      iVar4 = zmsg_get_offset(msg);
      uVar7 = (uint)local_14;
      uVar6 = zmsg_get_length(msg);
      if (uVar7 * 2 + iVar4 <= uVar6) {
        uVar1 = rx_info->nwk_dst_addr;
        uVar6 = nwk_get_short_address();
        if (uVar1 == uVar6) {
          iVar4 = core_globals_get();
          if ((*(char *)(iVar4 + 0x9f7) != '\0') &&
             (iVar4 = core_globals_get(), local_14 <= *(byte *)(iVar4 + 0x9de))) {
            if (local_14 == 0) {
              nwk_route_record_table_remove_by_dst();
            }
            else {
              iVar4 = nwk_route_record_table_find_or_create(rx_info->nwk_src_addr);
              if (iVar4 != 0) {
                *(byte *)(iVar4 + 2) = local_14;
                for (local_14 = 0; local_14 < *(byte *)(iVar4 + 2); local_14 = local_14 + 1) {
                  uVar5 = zmsg_get_offset(msg);
                  zmsg_read_bytes(msg,uVar5,2,(local_14 + 2) * 2 + iVar4);
                  zmsg_move_offset(msg,2);
                }
              }
            }
          }
        }
        else if ((rx_info->nwk_dst_addr < 0xfff8) &&
                (zmsg_read_bytes(msg,6,1,&bStack_13), 1 < bStack_13)) {
          uStack_12._0_1_ = bStack_13 - 1;
          zmsg_write_bytes(msg,6,&uStack_12);
          sVar3 = zmsg_get_offset(msg);
          uStack_12 = CONCAT11(uStack_12._1_1_,local_14 + 1);
          zmsg_write_bytes(msg,sVar3 + -1,1,&uStack_12);
          uStack_12 = nwk_get_short_address();
          zmsg_append_bytes(msg,2,&uStack_12);
          nwk_fwd_send_msg_delayed(msg,0);
          return;
        }
      }
    }
  }
  zmsg_free(msg);
  return;
}


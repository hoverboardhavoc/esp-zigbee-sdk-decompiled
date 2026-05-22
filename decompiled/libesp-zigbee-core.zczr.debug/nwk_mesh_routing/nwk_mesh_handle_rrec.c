/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_mesh_routing.o -> nwk_mesh_handle_rrec
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
  nwk_route_record_t *route_record;
  _Bool _Var2;
  short sVar3;
  undefined3 extraout_var;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  byte bStack_15;
  undefined2 uStack_14;
  uint8_t radius;
  uint8_t relay_count;
  
  _Var2 = nwk_is_router_started();
  if ((CONCAT31(extraout_var,_Var2) != 0) &&
     (iVar4 = nwk_secur_get_seclevel(), ((msg->flags & 2) != 0) == (iVar4 != 0))) {
    radius = '\0';
    zmsg_move_offset(msg,1);
    uVar5 = zmsg_get_offset(msg);
    zmsg_read_bytes(msg,uVar5,1,&radius);
    zmsg_move_offset(msg,1);
    iVar4 = zmsg_get_offset(msg);
    uVar7 = (uint)radius;
    uVar6 = zmsg_get_length(msg);
    if (iVar4 + uVar7 * 2 <= uVar6) {
      uVar1 = rx_info->nwk_dst_addr;
      uVar6 = nwk_get_short_address();
      if (uVar1 == uVar6) {
        iVar4 = core_globals_get();
        if ((*(char *)(iVar4 + 0x9f7) != '\0') &&
           (iVar4 = core_globals_get(), radius <= *(byte *)(iVar4 + 0x9de))) {
          if (radius == '\0') {
            nwk_route_record_table_remove_by_dst(rx_info->nwk_src_addr);
          }
          else {
            iVar4 = nwk_route_record_table_find_or_create(rx_info->nwk_src_addr);
            if (iVar4 == 0) goto _L0;
            *(uint8_t *)(iVar4 + 2) = radius;
            for (radius = '\0'; radius < *(byte *)(iVar4 + 2); radius = radius + '\x01') {
              uVar5 = zmsg_get_offset(msg);
              zmsg_read_bytes(msg,uVar5,2,(uint)radius * 2 + iVar4 + 4);
              zmsg_move_offset(msg,2);
            }
          }
          zmsg_free(msg);
          return;
        }
      }
      else if ((rx_info->nwk_dst_addr < 0xfff8) &&
              (zmsg_read_bytes(msg,6,1,&bStack_15), 1 < bStack_15)) {
        uStack_14._0_1_ = bStack_15 - 1;
        zmsg_write_bytes(msg,6,1,&uStack_14);
        sVar3 = zmsg_get_offset(msg);
        uStack_14 = CONCAT11(uStack_14._1_1_,radius + '\x01');
        zmsg_write_bytes(msg,sVar3 + -1,1,&uStack_14);
        uStack_14 = nwk_get_short_address();
        zmsg_append_bytes(msg,2,&uStack_14);
        nwk_fwd_send_msg_delayed(msg,0);
        return;
      }
    }
  }
_L0:
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_handle_rreq
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_mesh_handle_rreq(int param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  byte bStack_32;
  char cStack_31;
  uint uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined1 uStack_24;
  
  iVar5 = nwk_is_router_started();
  if (iVar5 == 0) {
    if (param_1 == 0) {
      return;
    }
    goto _L0;
  }
  iVar5 = nwk_secur_get_seclevel();
  if ((ushort)(iVar5 != 0) != (*(ushort *)(param_1 + 0x16) >> 1 & 1)) goto _L0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  zmsg_move_offset(param_1,1);
  uVar6 = zmsg_get_offset(param_1);
  zmsg_read_bytes(param_1,uVar6,0xd,&uStack_30);
  uVar1 = *(undefined2 *)(param_2 + 2);
  iVar5 = nwk_mesh_update_neighbor(param_2);
  if ((iVar5 == 0) ||
     (uVar3 = uStack_30 >> 0x10, 0xfff7 < uVar3 != (((int)(uStack_30 & 0xff) >> 3 & 3U) != 0)))
  goto _L0;
  uVar2 = *(undefined2 *)(param_2 + 6);
  uVar7 = nwk_neighbor_get_link_cost();
  uStack_2c = CONCAT31(uStack_2c._1_3_,(char)uStack_2c + (char)uVar7);
  iVar5 = core_globals_get();
  if ((*(char *)(iVar5 + 0x9f7) != '\0') && (uVar8 = nwk_get_short_address(), uVar3 == uVar8)) {
    nwk_concentrator_discovery();
  }
  iVar5 = nwk_mesh_route_discovery_update
                    (uStack_30 >> 8 & 0xff,(int)(uStack_30 & 0xff) >> 3 & 3,uStack_2c & 0xff,uVar2,
                     uVar1,uVar3);
  if (iVar5 != 0) goto _L0;
  nwk_route_table_add_rev_route(uVar2,uVar1,(int)(uStack_30 & 0xff) >> 3 & 3);
  iVar5 = nwk_neighbor_table_get_by_short(uVar3);
  if ((iVar5 != 0) && ((*(uint *)(iVar5 + 0xc) & 0x3c0) != 0x40)) {
    iVar5 = 0;
  }
  if (((int)(uStack_30 & 0xff) >> 3 & 3U) != 0) {
_L0:
    zmsg_read_bytes(param_1,6,1,&bStack_32);
    if (1 < bStack_32) {
      cStack_31 = bStack_32 - 1;
      zmsg_write_bytes(param_1,6,&cStack_31);
      sVar4 = zmsg_get_offset(param_1);
      cStack_31 = (char)uStack_2c;
      zmsg_write_bytes(param_1,sVar4 + 4,1,&cStack_31);
      nwk_fwd_send_msg_delayed(param_1,0);
      return;
    }
_L0:
    zmsg_free(param_1);
    return;
  }
  uVar8 = nwk_get_short_address();
  if (uVar3 == uVar8) {
    if (iVar5 == 0) goto _L0;
  }
  else if (iVar5 == 0) goto _L0;
  iVar5 = nwk_neighbor_get_link_cost(iVar5);
  uVar7 = iVar5 + uVar7 & 0xff;
_L0:
  nwk_mesh_send_rrep(param_1,uStack_30 >> 8 & 0xff,uVar7,uVar2,uVar3,uVar1);
  return;
}


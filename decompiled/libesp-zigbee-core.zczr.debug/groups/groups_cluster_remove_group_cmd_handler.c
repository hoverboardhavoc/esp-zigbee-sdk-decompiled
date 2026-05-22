/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_remove_group_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: group_id */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t groups_cluster_remove_group_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  bool bVar1;
  _Bool _Var2;
  ezb_zcl_status_t eVar3;
  uint uVar4;
  undefined3 extraout_var;
  int iVar5;
  undefined1 uVar6;
  uint unaff_s2;
  ushort uStack_16;
  uint16_t uStack_14;
  uint16_t uStack_12;
  uint16_t group_id;
  uint16_t offset;
  
  uStack_12 = 0;
  uStack_14 = 0xffff;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/groups.c",0x1dd,
                  "groups_cluster_remove_group_cmd_handler","packet && rsp");
_L0:
    iVar5 = aps_group_table_find(unaff_s2);
    if (iVar5 == 0) {
      uVar6 = 0x8b;
    }
    else {
      aps_group_table_remove_group(uStack_14);
      uVar6 = 0;
    }
  }
  else {
    af_read_le16(packet->payload,&uStack_12,&uStack_14);
    uVar4 = zmsg_get_length(packet->payload);
    if (uVar4 < uStack_12) {
      bVar1 = true;
      goto _L0;
    }
    unaff_s2 = (uint)uStack_14;
    _Var2 = groups_check_group_id_is_valid(uStack_14);
    if (CONCAT31(extraout_var,_Var2) != 0) goto _L0;
    uVar6 = 0x87;
  }
  uStack_16 = CONCAT11(uStack_16._1_1_,uVar6);
  zmsg_append_bytes(rsp->payload,1,&uStack_16);
  uStack_16 = uStack_14;
  zmsg_append_bytes(rsp->payload,2,&uStack_16);
  bVar1 = false;
_L0:
  if ((packet->header).dst_addr.u.short_addr < 0xfff8) {
    if (bVar1) {
      eVar3 = zcl_packet_setup_default_response(rsp,packet);
    }
    else {
      eVar3 = zcl_packet_setup_response(rsp,packet,3);
    }
  }
  else {
    eVar3 = 0xfe;
  }
  return eVar3;
}


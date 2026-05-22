/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_view_group_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t groups_cluster_view_group_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  _Bool _Var1;
  ezb_zcl_status_t eVar2;
  uint uVar3;
  undefined3 extraout_var;
  int iVar4;
  undefined4 uVar5;
  char cVar6;
  uint unaff_s2;
  ushort uStack_26;
  uint16_t uStack_24;
  uint16_t uStack_22;
  uint16_t group_id;
  uint16_t offset;
  
  uStack_22 = 0;
  uStack_24 = 0xffff;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/groups.c",0x148,
                  "groups_cluster_view_group_cmd_handler","packet && rsp");
_L0:
    iVar4 = aps_group_table_is_endpoint_in_group((packet->header).dst_ep,unaff_s2);
    if (iVar4 == 0) {
      cVar6 = -0x75;
    }
    else {
      cVar6 = '\0';
    }
_L0:
    uStack_26 = CONCAT11(uStack_26._1_1_,cVar6);
    zmsg_append_bytes(rsp->payload,1,&uStack_26);
    uStack_26 = uStack_24;
    zmsg_append_bytes(rsp->payload,2,&uStack_26);
    if (cVar6 == '\0') {
      groups_append_group_name(rsp->payload,0,(void *)0x0);
    }
    else {
      uStack_26 = uStack_26 & 0xff00;
      zmsg_append_bytes(rsp->payload,1,&uStack_26);
    }
    eVar2 = zcl_packet_setup_response(rsp,packet,1);
  }
  else {
    af_read_le16(packet->payload,&uStack_22,&uStack_24);
    uVar3 = zmsg_get_length(packet->payload);
    if (uVar3 < uStack_22) {
      uVar5 = 0x80;
    }
    else {
      if ((packet->header).dst_addr.u.short_addr < 0xfff8) {
        unaff_s2 = (uint)uStack_24;
        _Var1 = groups_check_group_id_is_valid(uStack_24);
        if (CONCAT31(extraout_var,_Var1) != 0) goto _L0;
        cVar6 = -0x79;
        goto _L0;
      }
      uVar5 = 0xfe;
    }
    eVar2 = zcl_packet_setup_default_response(rsp,packet,uVar5);
  }
  return eVar2;
}


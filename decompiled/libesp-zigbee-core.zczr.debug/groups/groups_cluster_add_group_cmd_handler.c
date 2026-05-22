/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_add_group_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t groups_cluster_add_group_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t uVar1;
  bool bVar2;
  uint16_t uVar3;
  _Bool _Var4;
  undefined1 uVar5;
  ezb_zcl_status_t eVar6;
  uint16_t uVar7;
  uint uVar8;
  undefined3 extraout_var;
  int iVar9;
  uint unaff_s2;
  uint16_t uStack_26;
  uint16_t uStack_24;
  uint16_t uStack_22;
  uint16_t group_id;
  uint16_t offset;
  
  uStack_22 = 0;
  uStack_24 = 0xffff;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/groups.c",0x100,
                  "groups_cluster_add_group_cmd_handler","packet && rsp");
_L0:
    iVar9 = ezb_zcl_is_identifying((packet->header).dst_ep);
    if (iVar9 == 0) {
      bVar2 = false;
      goto _L0;
    }
  }
  else {
    uVar8 = zmsg_get_length(packet->payload);
    af_read_le16(packet->payload,&uStack_22,&uStack_24);
    uVar3 = uStack_22;
    if (uStack_22 < uVar8) {
      uVar7 = groups_read_group_name(packet->payload,uStack_22,(void *)0x0);
      uStack_22 = uVar3 + uVar7;
    }
    if (uVar8 < uStack_22) {
      unaff_s2 = 0;
      bVar2 = true;
      goto _L0;
    }
    uVar1 = (packet->header).cmd_id;
    unaff_s2 = (uint)(uVar1 == '\x05');
    if (uVar1 == '\x05') goto _L0;
  }
  uVar3 = uStack_24;
  _Var4 = groups_check_group_id_is_valid(uStack_24);
  if (CONCAT31(extraout_var,_Var4) == 0) {
    uStack_26 = CONCAT11(uStack_26._1_1_,0x87);
    zmsg_append_bytes(rsp->payload,1,&uStack_26);
    bVar2 = false;
  }
  else {
    aps_group_table_add(uVar3,(packet->header).dst_ep);
    uVar5 = err_to_zcl_status();
    uStack_26 = CONCAT11(uStack_26._1_1_,uVar5);
    zmsg_append_bytes(rsp->payload,1,&uStack_26);
    uStack_26 = uStack_24;
    zmsg_append_bytes(rsp->payload,2,&uStack_26);
    bVar2 = false;
  }
_L0:
  if ((packet->header).dst_addr.u.short_addr < 0xfff8) {
    if ((bVar2) || (unaff_s2 != 0)) {
      eVar6 = zcl_packet_setup_default_response(rsp,packet);
    }
    else {
      eVar6 = zcl_packet_setup_response(rsp,packet);
    }
  }
  else {
    eVar6 = 0xfe;
  }
  return eVar6;
}


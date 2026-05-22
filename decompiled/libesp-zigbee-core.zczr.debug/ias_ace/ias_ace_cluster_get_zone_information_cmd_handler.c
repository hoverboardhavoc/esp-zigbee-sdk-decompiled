/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_zone_information_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ias_ace_cluster_get_zone_information_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  undefined1 uVar1;
  uint16_t uVar2;
  undefined2 extraout_var;
  ias_ace_zone_table_t *zone_table;
  int iVar3;
  zcl_packet_payload_t *pzVar4;
  ezb_zcl_ias_ace_zone_table_ent_t *unaff_s2;
  uint uStack_38;
  undefined4 uStack_34;
  uint uStack_2c;
  ezb_extaddr_t zone_address;
  uint8_t zone_id;
  uint16_t offset;
  
  zone_address.field_0.u64._6_2_ = 0;
  zone_address.field_0.u8[5] = '\0';
  uStack_2c = 0;
  zone_address.field_0.u64._0_4_ = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    pzVar4 = (zcl_packet_payload_t *)
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",
                           0x169,"ias_ace_cluster_get_zone_information_cmd_handler","packet && rsp")
    ;
_L0:
    uVar2 = 0xffff;
_L312:
    uStack_38 = CONCAT22(uStack_38._2_2_,uVar2);
    iVar3 = zmsg_append_bytes(pzVar4,2,&uStack_38);
    if (iVar3 == 0) {
      if (unaff_s2 == (ezb_zcl_ias_ace_zone_table_ent_t *)0x0) {
        uStack_2c = 0xffffffff;
        zone_address.field_0.u64._0_4_ = 0xffffffff;
      }
      else {
        uStack_2c = *(uint *)&(unaff_s2->zone_address).field_0;
        zone_address.field_0.u64._0_4_ = *(undefined4 *)((int)&(unaff_s2->zone_address).field_0 + 4)
        ;
      }
      uStack_38 = uStack_2c;
      uStack_34 = zone_address.field_0.u64._0_4_;
      iVar3 = zmsg_append_bytes(rsp->payload,8,&uStack_38);
      if (iVar3 == 0) {
        if ((unaff_s2 == (ezb_zcl_ias_ace_zone_table_ent_t *)0x0) || (unaff_s2->zone_label[0] == 0))
        {
          uStack_38 = uStack_38 & 0xffffff00;
          iVar3 = zmsg_append_bytes(rsp->payload,1,&uStack_38);
          if (iVar3 == 0) goto _L0;
          iVar3 = 0x89;
        }
        else {
          iVar3 = zmsg_append_bytes(rsp->payload,unaff_s2->zone_label[0] + 1,unaff_s2->zone_label);
          if (iVar3 == 0) {
_L0:
            iVar3 = zcl_packet_setup_response(rsp,packet,2);
            if (iVar3 == 0) goto _L0;
          }
          else {
            iVar3 = 0x89;
          }
        }
      }
      else {
        iVar3 = 0x89;
      }
    }
    else {
      iVar3 = 0x89;
    }
  }
  else {
    uVar2 = af_read_le8(packet->payload,(uint16_t *)(zone_address.field_0.u8 + 6),
                        zone_address.field_0.u8 + 5);
    if (CONCAT22(extraout_var,uVar2) == 1) {
      if (zone_address.field_0.u8[5] == 0xff) {
        iVar3 = 0x87;
      }
      else {
        zone_table = (ias_ace_zone_table_t *)ezb_zcl_ias_ace_get_zone_table((packet->header).dst_ep)
        ;
        uVar1 = zone_address.field_0.u8[5];
        if (zone_table == (ias_ace_zone_table_t *)0x0) {
          iVar3 = 0x80;
        }
        else {
          unaff_s2 = ias_ace_zone_table_get_zone(zone_table,zone_address.field_0.u8[5]);
          uStack_38 = CONCAT31(uStack_38._1_3_,uVar1);
          iVar3 = zmsg_append_bytes(rsp->payload,1,&uStack_38);
          if (iVar3 == 0) {
            pzVar4 = rsp->payload;
            if (unaff_s2 == (ezb_zcl_ias_ace_zone_table_ent_t *)0x0) goto _L0;
            uVar2 = unaff_s2->zone_type;
            goto _L312;
          }
          iVar3 = 0x89;
        }
      }
    }
    else {
      iVar3 = 0x80;
    }
  }
  iVar3 = zcl_packet_setup_default_response(rsp,packet,iVar3);
_L0:
  return (ezb_zcl_status_t)iVar3;
}


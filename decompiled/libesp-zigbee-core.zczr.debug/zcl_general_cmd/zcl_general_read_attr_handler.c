/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_read_attr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_general_read_attr_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  zcl_status_t zVar1;
  uint uVar2;
  zcl_attr_desc_t *attr_desc;
  undefined3 extraout_var;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  zmsg_t *unaff_s5;
  uint16_t uVar7;
  undefined4 uStack_3c;
  uint32_t time;
  uint16_t uStack_34;
  uint16_t offset;
  anon_struct_2_1_5b20b909 read_attr_req;
  
  uStack_34 = 0;
  if ((((packet == (zcl_packet_t *)0x0) ||
       (unaff_s5 = packet->payload, unaff_s5 == (zcl_packet_payload_t *)0x0)) ||
      (rsp == (zcl_packet_t *)0x0)) || (rsp->payload == (zcl_packet_payload_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x72,
                  "zcl_general_read_attr_handler","packet && packet->payload && rsp && rsp->payload"
                 );
  }
  else if (((packet->header).fc & 4) != 0) {
    uVar7 = (packet->header).manuf_code;
    goto _L0;
  }
  uVar7 = 0;
_L0:
  uVar2 = zmsg_get_length(unaff_s5);
  time._2_2_ = 0;
  if ((uVar2 & 1) == 0) {
_L0:
    if (time._2_2_ < uVar2) {
      uStack_34 = 0;
      af_read_le16(unaff_s5,(uint16_t *)((int)&time + 2),&uStack_34);
      if (((packet->header).fc & 8) == 0) {
        uVar6 = 1;
      }
      else {
        uVar6 = 2;
      }
      attr_desc = (zcl_attr_desc_t *)
                  zcl_get_attr_desc((packet->header).dst_ep,(packet->header).cluster_id,uVar6,
                                    uStack_34,uVar7);
      zVar1 = check_read_attr_filed(attr_desc);
      uVar3 = zcl_packet_max_available_space
                        ((packet->header).cluster_id,0,(packet->header).fc >> 2 & 1);
      uVar4 = zmsg_get_length(rsp->payload);
      if (uVar3 <= uVar4) {
        uVar6 = 0x89;
        goto _L0;
      }
      uStack_3c = CONCAT22(uStack_3c._2_2_,uStack_34);
      zmsg_append_bytes(rsp->payload,2,&uStack_3c);
      uStack_3c = CONCAT31(uStack_3c._1_3_,zVar1);
      zmsg_append_bytes(rsp->payload,1,&uStack_3c);
      if (CONCAT31(extraout_var,zVar1) == 0) {
        uStack_3c = CONCAT31(uStack_3c._1_3_,attr_desc->type);
        zmsg_append_bytes(rsp->payload,1,&uStack_3c);
        if (((packet->header).cluster_id == 10) && (((packet->header).fc & 8) == 0)) {
          if (((ushort)(attr_desc->id - 6) < 2) || (attr_desc->id == 0)) {
            uStack_3c = 0;
            iVar5 = zcl_time_cluster_read_time((packet->header).dst_ep,attr_desc->id,&uStack_3c);
            if (iVar5 != 0) {
              uVar6 = 0x8b;
              goto _L0;
            }
            zcl_packet_append_variable_attr_value(rsp->payload,attr_desc->type,&uStack_3c);
            goto _L0;
          }
        }
        zcl_packet_append_variable_attr_value(rsp->payload,attr_desc->type,attr_desc->data_p);
      }
      goto _L0;
    }
    zVar1 = zcl_packet_setup_response(rsp,packet,1);
  }
  else {
    uVar6 = 0x80;
_L0:
    zVar1 = zcl_packet_setup_default_response(rsp,packet,uVar6);
  }
  return zVar1;
}


/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_cmd_read_reporting_configuration_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: read_rep_cfg */
/* WARNING: Unknown calling convention */

zcl_status_t zcl_cmd_read_reporting_configuration_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  char cVar1;
  zcl_status_t zVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  uint uVar5;
  zcl_attr_desc_t *attr_desc;
  undefined3 extraout_var;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  zmsg_t *unaff_s2;
  uint16_t uVar9;
  uint16_t uStack_38;
  uint16_t uStack_36;
  uint8_t uStack_34;
  undefined1 uStack_33;
  uint16_t offset;
  zcl_read_reporting_configuration_req_t read_rep_cfg;
  
  uStack_34 = '\0';
  uStack_33 = 0;
  offset = 0;
  if ((((packet == (zcl_packet_t *)0x0) ||
       (unaff_s2 = packet->payload, unaff_s2 == (zcl_packet_payload_t *)0x0)) ||
      (rsp == (zcl_packet_t *)0x0)) || (rsp->payload == (zcl_packet_payload_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x2d6,
                  "zcl_cmd_read_reporting_configuration_handler",
                  "packet && packet->payload && rsp && rsp->payload");
  }
  else if (((packet->header).fc & 4) != 0) {
    uVar9 = (packet->header).manuf_code;
    goto _L0;
  }
  uVar9 = 0;
_L0:
  puVar3 = (undefined1 *)af_get_ep_desc((packet->header).dst_ep);
  if (puVar3 == (undefined1 *)0x0) {
    uVar8 = 0x81;
  }
  else {
    if (((packet->header).fc & 8) == 0) {
      uVar8 = 1;
    }
    else {
      uVar8 = 2;
    }
    puVar4 = (undefined2 *)af_endpoint_get_cluster_desc(puVar3,(packet->header).cluster_id,uVar8);
    if (puVar4 == (undefined2 *)0x0) {
      uVar8 = 0xc3;
    }
    else {
      uVar5 = zmsg_get_length(unaff_s2);
      uStack_36 = 0;
      while( true ) {
        if (uVar5 <= uStack_36) {
          zVar2 = zcl_packet_setup_response(rsp,packet,9);
          return zVar2;
        }
        af_read_le8(unaff_s2,&uStack_36,&stack0xffffffcc);
        af_read_le16(unaff_s2,&uStack_36,&offset);
        if (uVar5 < uStack_36) break;
        attr_desc = (zcl_attr_desc_t *)
                    zcl_cluster_get_attr_desc(puVar4,(uint)_uStack_34 >> 0x10,uVar9);
        zVar2 = check_read_reporting_configuration_field
                          ((zcl_read_reporting_configuration_req_t *)&stack0xffffffcc,attr_desc);
        if (CONCAT31(extraout_var,zVar2) == 0) {
          iVar6 = zcl_reporting_info_find
                            (*puVar3,*puVar4,*(undefined1 *)(puVar4 + 1),attr_desc->id,
                             attr_desc->manuf_code);
          cVar1 = '\0';
          if (iVar6 == 0) {
            cVar1 = -0x75;
          }
          uStack_38._0_1_ = cVar1;
          zmsg_append_bytes(rsp->payload,1,&uStack_38);
          uStack_38 = CONCAT11(uStack_38._1_1_,uStack_34);
          zmsg_append_bytes(rsp->payload,1,&uStack_38);
          uStack_38 = offset;
          zmsg_append_bytes(rsp->payload,2,&uStack_38);
          if (cVar1 == '\0') {
            if (uStack_34 == '\0') {
              uStack_38 = CONCAT11(uStack_38._1_1_,attr_desc->type);
              zmsg_append_bytes(rsp->payload,1,&uStack_38);
              uStack_38 = *(uint16_t *)(iVar6 + 0x10);
              zmsg_append_bytes(rsp->payload,2,&uStack_38);
              uStack_38 = *(uint16_t *)(iVar6 + 0x12);
              zmsg_append_bytes(rsp->payload,2,&uStack_38);
              iVar7 = zcl_attr_type_is_analog(attr_desc->type);
              if (iVar7 != 0) {
                zcl_packet_append_variable_attr_value(rsp->payload,attr_desc->type,iVar6 + 0x18);
              }
            }
            else {
              uStack_38 = *(uint16_t *)(iVar6 + 0x10);
              zmsg_append_bytes(rsp->payload,2,&uStack_38);
            }
          }
        }
        else {
          uStack_38._0_1_ = zVar2;
          zmsg_append_bytes(rsp->payload,1,&uStack_38);
          uStack_38 = CONCAT11(uStack_38._1_1_,uStack_34);
          zmsg_append_bytes(rsp->payload,1,&uStack_38);
          uStack_38 = offset;
          zmsg_append_bytes(rsp->payload,2,&uStack_38);
        }
      }
      uVar8 = 0x80;
    }
  }
  zVar2 = zcl_packet_setup_default_response(rsp,packet,uVar8);
  return zVar2;
}


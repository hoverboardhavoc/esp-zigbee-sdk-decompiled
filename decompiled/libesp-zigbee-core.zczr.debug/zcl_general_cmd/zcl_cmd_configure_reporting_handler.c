/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_cmd_configure_reporting_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

zcl_status_t zcl_cmd_configure_reporting_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  zcl_status_t zVar1;
  undefined1 uVar2;
  _Bool _Var3;
  int iVar4;
  int iVar5;
  uint uVar6;
  zcl_attr_desc_t *attr_desc;
  undefined3 extraout_var;
  char *pcVar7;
  size_t __size;
  int iVar8;
  undefined3 extraout_var_00;
  undefined4 uVar9;
  zmsg_t *unaff_s3;
  uint16_t uVar10;
  uint16_t uStack_44;
  uint16_t local_42;
  undefined1 auStack_40 [2];
  uint16_t offset;
  zcl_configure_reporting_req_t config_reporting_req;
  
  _auStack_40 = 0;
  config_reporting_req.direction = '\0';
  config_reporting_req._1_1_ = 0;
  config_reporting_req.attr_id = 0;
  config_reporting_req.field_2._0_4_ = 0;
  config_reporting_req.field_2._4_4_ = 0;
  if (packet == (zcl_packet_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x239,
                  "zcl_cmd_configure_reporting_handler","packet");
  }
  else {
    unaff_s3 = packet->payload;
    if (((packet->header).fc & 4) != 0) {
      uVar10 = (packet->header).manuf_code;
      goto _L0;
    }
  }
  uVar10 = 0;
_L0:
  iVar4 = af_get_ep_desc((packet->header).dst_ep);
  if (iVar4 == 0) {
    iVar4 = 0x81;
  }
  else {
    if (((packet->header).fc & 8) == 0) {
      uVar9 = 1;
    }
    else {
      uVar9 = 2;
    }
    iVar5 = af_endpoint_get_cluster_desc((packet->header).cluster_id,uVar9);
    if (iVar5 == 0) {
      iVar4 = 0xc3;
    }
    else {
      uVar6 = zmsg_get_length(unaff_s3);
      local_42 = 0;
      while (local_42 < uVar6) {
        _auStack_40 = 0;
        config_reporting_req.direction = '\0';
        config_reporting_req._1_1_ = 0;
        config_reporting_req.attr_id = 0;
        config_reporting_req.field_2._0_4_ = 0;
        config_reporting_req.field_2._4_4_ = 0;
        af_read_le8(unaff_s3,&local_42,auStack_40);
        af_read_le16(unaff_s3,&local_42,&offset);
        if (auStack_40[0] == '\0') {
          af_read_le8(unaff_s3,&local_42,&config_reporting_req.direction);
          af_read_le16(unaff_s3,&local_42,&config_reporting_req.attr_id);
          af_read_le16(unaff_s3,&local_42,&config_reporting_req.field_2.recv_info.timeout);
          iVar4 = zcl_attr_type_is_analog(config_reporting_req._0_4_ & 0xff);
          if (iVar4 != 0) {
            __size = zcl_packet_read_variable_attr_size
                               (packet->payload,local_42,config_reporting_req._0_4_ & 0xff);
            config_reporting_req.field_2._4_4_ = calloc(1,__size);
            zcl_packet_read_variable_attr_value
                      (unaff_s3,&local_42,config_reporting_req._0_4_ & 0xff,
                       config_reporting_req.field_2._4_4_);
          }
        }
        else {
          af_read_le16(unaff_s3,&local_42,(uint16_t *)&config_reporting_req);
        }
        if (uVar6 < local_42) {
          iVar4 = 0x80;
          goto _L0;
        }
        attr_desc = (zcl_attr_desc_t *)zcl_cluster_get_attr_desc(iVar5,_auStack_40 >> 0x10,uVar10);
        zVar1 = check_configure_reporting_field
                          ((zcl_configure_reporting_req_t *)auStack_40,attr_desc);
        if (CONCAT31(extraout_var,zVar1) == 0) {
          if (((packet->header).fc & 8) == 0) {
            uVar9 = 1;
          }
          else {
            uVar9 = 2;
          }
          pcVar7 = (char *)zcl_reporting_info_find
                                     ((packet->header).dst_ep,(packet->header).cluster_id,uVar9,
                                      _auStack_40 >> 0x10,attr_desc->manuf_code);
          if (pcVar7 == (char *)0x0) {
            if (((packet->header).fc & 8) == 0) {
              uVar9 = 1;
            }
            else {
              uVar9 = 2;
            }
            pcVar7 = (char *)zcl_reporting_info_create
                                       ((packet->header).dst_ep,(packet->header).profile_id,
                                        auStack_40[0] != '\0',(packet->header).cluster_id,uVar9,
                                        _auStack_40 >> 0x10,attr_desc->manuf_code);
            zcl_reporting_info_add();
            iVar8 = err_to_zcl_status();
          }
          else {
            iVar8 = 0;
          }
          uVar9 = config_reporting_req._0_4_;
          iVar4 = 0;
          if (iVar8 != 0) goto _L0;
          if (*pcVar7 == '\0') {
            *(uint16_t *)(pcVar7 + 0x10) = config_reporting_req.attr_id;
            ((anon_struct_2_1_35098041_for_recv_info *)(pcVar7 + 0x12))->timeout =
                 (uint16_t)config_reporting_req.field_2.recv_info.timeout;
            _Var3 = reportable_change_is_present
                              (config_reporting_req.attr_id,
                               (uint16_t)config_reporting_req.field_2.recv_info.timeout,
                               config_reporting_req.direction);
            if (CONCAT31(extraout_var_00,_Var3) != 0) {
              zcl_write_attr_value
                        (pcVar7 + 0x18,config_reporting_req.field_2._4_4_,
                         config_reporting_req._0_4_ & 0xff);
            }
          }
          else {
            pcVar7[0x10] = config_reporting_req.direction;
            pcVar7[0x11] = config_reporting_req._1_1_;
            config_reporting_req._0_4_ = uVar9;
          }
          zcl_reporting_info_update(pcVar7);
          uVar2 = err_to_zcl_status();
          uStack_44 = CONCAT11(uStack_44._1_1_,uVar2);
          zmsg_append_bytes(rsp->payload,1,&uStack_44);
        }
        else {
          uStack_44._0_1_ = zVar1;
          zmsg_append_bytes(rsp->payload,1,&uStack_44);
          uStack_44 = CONCAT11(uStack_44._1_1_,auStack_40[0]);
          zmsg_append_bytes(rsp->payload,1,&uStack_44);
          uStack_44 = offset;
          zmsg_append_bytes(rsp->payload,2,&uStack_44);
        }
        if (config_reporting_req.field_2._4_4_ != 0) {
          mm_free();
          config_reporting_req.field_2._4_4_ = 0;
        }
      }
      iVar4 = 0;
    }
  }
_L0:
  if (config_reporting_req.field_2._4_4_ != 0) {
    mm_free();
  }
  if (iVar4 == 0) {
    zVar1 = zcl_packet_setup_response(rsp,packet,7);
  }
  else {
    zVar1 = zcl_packet_setup_default_response(rsp,packet,iVar4);
  }
  return zVar1;
}


/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_op_simple_desc_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_simple_desc_rsp
          (zdo_packet_payload_t *payload,zdp_simple_desc_rsp_field_t *rsp,_Bool is_write)

{
  uint8_t uVar1;
  uint unaff_s1;
  uint uVar2;
  int iVar3;
  uint16_t *puVar4;
  undefined3 in_register_00002031;
  undefined4 unaff_s3;
  uint uVar5;
  uint __nmemb;
  byte bStack_23;
  uint16_t uStack_22;
  uint8_t device_info;
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) || (rsp == (zdp_simple_desc_rsp_field_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x30d,
                  "zdo_op_simple_desc_rsp","payload && rsp");
  }
  else {
    if (CONCAT31(in_register_00002031,is_write) == 0) {
      uStack_22 = 0;
      bStack_23 = 0;
      uVar5 = zmsg_get_length();
      af_read_le8(payload,&uStack_22,&rsp->status);
      af_read_le16(payload,&uStack_22,&rsp->nwk_addr_of_interest);
      af_read_le8(payload,&uStack_22,&rsp->length);
      if ((int)uVar5 < (int)((uint)uStack_22 + (uint)rsp->length)) {
        unaff_s1 = 0xfe;
      }
      else {
        if (rsp->status == '\0') {
          af_read_le8(payload,&uStack_22,&(rsp->desc).ep_id);
          af_read_le16(payload,&uStack_22,&(rsp->desc).app_profile_id);
          af_read_le16(payload,&uStack_22,&(rsp->desc).app_device_id);
          af_read_le8(payload,&uStack_22,&bStack_23);
          (rsp->desc).field_0x6 = (rsp->desc).field_0x6 & 0xf0 | bStack_23 >> 4;
          (rsp->desc).field_0x6 = (byte)((bStack_23 & 0xf) << 4) | bStack_23 >> 4;
          af_read_le8(payload,&uStack_22,&(rsp->desc).app_input_cluster_count);
          __nmemb = (uint)(rsp->desc).app_input_cluster_count;
          puVar4 = (uint16_t *)calloc(__nmemb,2);
          (rsp->desc).app_cluster_list = puVar4;
          uVar2 = 0;
          if (puVar4 == (uint16_t *)0x0) {
            if (__nmemb != 0) {
              unaff_s1 = 0x8a;
              goto _L0;
            }
            uVar2 = 0;
          }
          for (; uVar2 < (rsp->desc).app_input_cluster_count; uVar2 = uVar2 + 1 & 0xff) {
            af_read_le16(payload,&uStack_22,(rsp->desc).app_cluster_list + uVar2);
          }
          af_read_le8(payload,&uStack_22,&(rsp->desc).app_output_cluster_count);
          puVar4 = (uint16_t *)
                   mm_realloc((rsp->desc).app_cluster_list,
                              (uint)(rsp->desc).app_input_cluster_count +
                              (uint)(rsp->desc).app_output_cluster_count,2);
          (rsp->desc).app_cluster_list = puVar4;
          if ((puVar4 == (uint16_t *)0x0) &&
             ((uint)(rsp->desc).app_input_cluster_count + (uint)(rsp->desc).app_output_cluster_count
              != 0)) {
            unaff_s1 = 0x8a;
            goto _L0;
          }
          for (uVar2 = (uint)(rsp->desc).app_input_cluster_count;
              uVar2 < (uint)(rsp->desc).app_input_cluster_count +
                      (uint)(rsp->desc).app_output_cluster_count; uVar2 = uVar2 + 1 & 0xff) {
            af_read_le16(payload,&uStack_22,(rsp->desc).app_cluster_list + uVar2);
          }
        }
        if (uVar5 < uStack_22) {
          unaff_s1 = 0xfe;
        }
        else {
          unaff_s1 = 0;
        }
      }
      goto _L0;
    }
    uStack_22 = CONCAT11(uStack_22._1_1_,rsp->status);
    iVar3 = zmsg_append_bytes(1,&uStack_22);
    if (iVar3 != 0) {
      unaff_s1 = 0x8a;
      goto _L0;
    }
    uStack_22 = rsp->nwk_addr_of_interest;
    iVar3 = zmsg_append_bytes(payload,2,&uStack_22);
    if (iVar3 != 0) {
      unaff_s1 = 0x8a;
      goto _L0;
    }
    unaff_s3 = zmsg_get_length(payload);
    uStack_22 = CONCAT11(uStack_22._1_1_,rsp->length);
    iVar3 = zmsg_append_bytes(payload,1,&uStack_22);
    if (iVar3 != 0) {
      unaff_s1 = 0x8a;
      goto _L0;
    }
    unaff_s1 = (uint)rsp->status;
    if (unaff_s1 != 0) {
      unaff_s1 = 0;
      goto _L0;
    }
  }
  uVar1 = rsp->length;
  rsp->length = uVar1 + '\x01';
  rsp->length = uVar1 + '\x03';
  rsp->length = uVar1 + '\x05';
  rsp->length = uVar1 + '\x06';
  rsp->length = uVar1 + '\b';
  uStack_22 = CONCAT11(uStack_22._1_1_,(rsp->desc).ep_id);
  iVar3 = zmsg_append_bytes(payload,1,&uStack_22);
  if (iVar3 == 0) {
    uStack_22 = (rsp->desc).app_profile_id;
    iVar3 = zmsg_append_bytes(payload,2,&uStack_22);
    if (iVar3 == 0) {
      uStack_22 = (rsp->desc).app_device_id;
      iVar3 = zmsg_append_bytes(payload,2,&uStack_22);
      if (iVar3 == 0) {
        uVar5._0_2_ = (rsp->desc).app_device_id;
        uVar5._2_1_ = (rsp->desc).field_0x6;
        uVar5._3_1_ = (rsp->desc).app_input_cluster_count;
        uStack_22._0_1_ = (byte)(uVar5 >> 0x14) & 0xf | (byte)((uVar5 >> 0x10 & 0xf) << 4);
        iVar3 = zmsg_append_bytes(payload,1,&uStack_22);
        if (iVar3 == 0) {
          uStack_22 = CONCAT11(uStack_22._1_1_,(rsp->desc).app_input_cluster_count);
          iVar3 = zmsg_append_bytes(payload,1,&uStack_22);
          uVar5 = unaff_s1;
          if (iVar3 == 0) {
            for (; uVar5 < (rsp->desc).app_input_cluster_count; uVar5 = uVar5 + 1 & 0xff) {
              uStack_22 = (rsp->desc).app_cluster_list[uVar5];
              iVar3 = zmsg_append_bytes(payload,2,&uStack_22);
              if (iVar3 != 0) {
                unaff_s1 = 0x8a;
                goto _L0;
              }
              rsp->length = rsp->length + '\x02';
            }
            uStack_22 = CONCAT11(uStack_22._1_1_,(rsp->desc).app_output_cluster_count);
            iVar3 = zmsg_append_bytes(payload,1,&uStack_22);
            if (iVar3 == 0) {
              for (uVar5 = (uint)(rsp->desc).app_input_cluster_count;
                  uVar5 < (uint)(rsp->desc).app_input_cluster_count +
                          (uint)(rsp->desc).app_output_cluster_count; uVar5 = uVar5 + 1 & 0xff) {
                uStack_22 = (rsp->desc).app_cluster_list[uVar5];
                iVar3 = zmsg_append_bytes(payload,2,&uStack_22);
                if (iVar3 != 0) {
                  unaff_s1 = 0x8a;
                  goto _L0;
                }
                rsp->length = rsp->length + '\x02';
              }
              uStack_22 = CONCAT11(uStack_22._1_1_,rsp->length);
              zmsg_write_bytes(payload,unaff_s3,1,&uStack_22);
            }
            else {
              unaff_s1 = 0x8a;
            }
          }
          else {
            unaff_s1 = 0x8a;
          }
        }
        else {
          unaff_s1 = 0x8a;
        }
      }
      else {
        unaff_s1 = 0x8a;
      }
    }
    else {
      unaff_s1 = 0x8a;
    }
  }
  else {
    unaff_s1 = 0x8a;
  }
_L0:
  return (zdp_status_t)unaff_s1;
}


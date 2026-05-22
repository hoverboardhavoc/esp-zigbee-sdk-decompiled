/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_op_nwk_addr_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_nwk_addr_rsp(zdo_packet_payload_t *payload,uint8_t request_type,zdp_nwk_addr_rsp_field_t *rsp
                   ,_Bool is_write)

{
  int iVar1;
  ezb_shortaddr_t *peVar2;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002035;
  uint uVar3;
  uint uVar4;
  zdp_status_t unaff_s3;
  uint16_t auStack_22 [2];
  uint16_t offset;
  
  uVar3 = CONCAT31(in_register_0000202d,request_type);
  if ((payload != (zdo_packet_payload_t *)0x0) && (rsp != (zdp_nwk_addr_rsp_field_t *)0x0)) {
    if (CONCAT31(in_register_00002035,is_write) == 0) {
      auStack_22[0] = 0;
      uVar3 = zmsg_get_length();
      af_read_le8(payload,auStack_22,&rsp->status);
      af_read_bytes(payload,auStack_22,8,(uint8_t *)&rsp->ieee_addr_remote_dev);
      af_read_le16(payload,auStack_22,&rsp->nwk_addr_remote_dev);
      if ((rsp->status == '\0') && (auStack_22[0] < uVar3)) {
        af_read_le8(payload,auStack_22,&rsp->num_assoc_dev);
        if (rsp->num_assoc_dev != 0) {
          peVar2 = (ezb_shortaddr_t *)calloc((uint)rsp->num_assoc_dev,2);
          rsp->nwk_addr_assoc_dev_list = peVar2;
          if (peVar2 == (ezb_shortaddr_t *)0x0) {
            return 0x8a;
          }
          af_read_le8(payload,auStack_22,&rsp->start_index);
          for (uVar4 = 0; uVar4 < rsp->num_assoc_dev; uVar4 = uVar4 + 1 & 0xff) {
            af_read_le16(payload,auStack_22,rsp->nwk_addr_assoc_dev_list + uVar4);
          }
        }
      }
      else {
        rsp->num_assoc_dev = '\0';
        rsp->start_index = '\0';
        rsp->nwk_addr_assoc_dev_list = (ezb_shortaddr_t *)0x0;
      }
      if (uVar3 < auStack_22[0]) {
        unaff_s3 = 0xfe;
      }
      else {
        unaff_s3 = '\0';
      }
    }
    else {
      auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,rsp->status);
      iVar1 = zmsg_append_bytes(1,auStack_22);
      if (iVar1 == 0) {
        iVar1 = zmsg_append_bytes(payload,8,&rsp->ieee_addr_remote_dev);
        if (iVar1 == 0) {
          auStack_22[0] = rsp->nwk_addr_remote_dev;
          iVar1 = zmsg_append_bytes(payload,2,auStack_22);
          if (iVar1 == 0) {
            if (rsp->status == '\0') {
              unaff_s3 = '\0';
              if (uVar3 == 1) {
                auStack_22[0]._0_1_ = rsp->num_assoc_dev;
                iVar1 = zmsg_append_bytes(payload,1,auStack_22);
                if (iVar1 == 0) {
                  if (rsp->num_assoc_dev == '\0') {
                    unaff_s3 = '\0';
                  }
                  else if (rsp->nwk_addr_assoc_dev_list != (ezb_shortaddr_t *)0x0) {
                    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,rsp->start_index);
                    iVar1 = zmsg_append_bytes(payload,1,auStack_22);
                    if (iVar1 == 0) {
                      unaff_s3 = '\0';
                      for (uVar3 = 0; uVar3 < rsp->num_assoc_dev; uVar3 = uVar3 + 1 & 0xff) {
                        auStack_22[0] = rsp->nwk_addr_assoc_dev_list[uVar3];
                        iVar1 = zmsg_append_bytes(payload,2,auStack_22);
                        if (iVar1 != 0) {
                          return 0x8a;
                        }
_L0:
                      }
                    }
                    else {
                      unaff_s3 = 0x8a;
                    }
                  }
                }
                else {
                  unaff_s3 = 0x8a;
                }
              }
            }
            else {
              unaff_s3 = '\0';
            }
          }
          else {
            unaff_s3 = 0x8a;
          }
        }
        else {
          unaff_s3 = 0x8a;
        }
      }
      else {
        unaff_s3 = 0x8a;
      }
    }
    return unaff_s3;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x61,
                "zdo_op_nwk_addr_rsp","payload && rsp");
  goto _L0;
}


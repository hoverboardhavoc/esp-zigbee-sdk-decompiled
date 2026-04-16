/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_op_nwk_addr_rsp
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
  zdp_nwk_addr_rsp_field_t *unaff_s0;
  ezb_err_t eVar1;
  ezb_shortaddr_t *peVar2;
  undefined3 in_register_0000202d;
  int iVar3;
  int extraout_a1;
  undefined3 in_register_00002035;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint16_t auStack_22 [2];
  uint16_t offset;
  
  iVar4 = CONCAT31(in_register_00002035,is_write);
  iVar3 = CONCAT31(in_register_0000202d,request_type);
  if ((payload == (zdo_packet_payload_t *)0x0) ||
     (unaff_s0 = rsp, rsp == (zdp_nwk_addr_rsp_field_t *)0x0)) {
    iVar4 = 0;
    rsp = (zdp_nwk_addr_rsp_field_t *)0x0;
    payload = (zdo_packet_payload_t *)__assert_func(0,0);
    iVar3 = extraout_a1;
  }
  if (iVar4 == 0) {
    auStack_22[0] = 0;
    uVar5 = zmsg_get_length();
    af_read_le8(payload,auStack_22,&unaff_s0->status);
    af_read_bytes(payload,auStack_22,8,(uint8_t *)&unaff_s0->ieee_addr_remote_dev);
    af_read_le16(payload,auStack_22,&unaff_s0->nwk_addr_remote_dev);
    if ((unaff_s0->status == '\0') && (auStack_22[0] < uVar5)) {
      af_read_le8(payload,auStack_22,&unaff_s0->num_assoc_dev);
      if (unaff_s0->num_assoc_dev != 0) {
        peVar2 = (ezb_shortaddr_t *)calloc((uint)unaff_s0->num_assoc_dev,2);
        unaff_s0->nwk_addr_assoc_dev_list = peVar2;
        if (peVar2 == (ezb_shortaddr_t *)0x0) {
          return 0x8a;
        }
        af_read_le8(payload,auStack_22,&unaff_s0->start_index);
        for (uVar6 = 0; uVar6 < unaff_s0->num_assoc_dev; uVar6 = uVar6 + 1 & 0xff) {
          af_read_le16(payload,auStack_22,unaff_s0->nwk_addr_assoc_dev_list + uVar6);
        }
      }
    }
    else {
      unaff_s0->num_assoc_dev = '\0';
      unaff_s0->start_index = '\0';
      unaff_s0->nwk_addr_assoc_dev_list = (ezb_shortaddr_t *)0x0;
    }
    if (uVar5 < auStack_22[0]) {
      return 0xfe;
    }
  }
  else {
    eVar1 = zmsg_append_u8(payload,rsp->status);
    if (((eVar1 != 0) ||
        (iVar4 = zmsg_append_bytes(payload,8,&unaff_s0->ieee_addr_remote_dev), iVar4 != 0)) ||
       (eVar1 = zmsg_append_le16(payload,unaff_s0->nwk_addr_remote_dev), eVar1 != 0)) {
      return 0x8a;
    }
    if ((unaff_s0->status == '\0') && (iVar3 == 1)) {
      eVar1 = zmsg_append_u8(payload,unaff_s0->num_assoc_dev);
      if (eVar1 != 0) {
        return 0x8a;
      }
      if ((unaff_s0->num_assoc_dev != '\0') &&
         (unaff_s0->nwk_addr_assoc_dev_list != (ezb_shortaddr_t *)0x0)) {
        eVar1 = zmsg_append_u8(payload,unaff_s0->start_index);
        uVar5 = 0;
        if (eVar1 != 0) {
          return 0x8a;
        }
        for (; uVar5 < unaff_s0->num_assoc_dev; uVar5 = uVar5 + 1 & 0xff) {
          eVar1 = zmsg_append_le16(payload,unaff_s0->nwk_addr_assoc_dev_list[uVar5]);
          if (eVar1 != 0) {
            return 0x8a;
          }
        }
      }
    }
  }
  return '\0';
}


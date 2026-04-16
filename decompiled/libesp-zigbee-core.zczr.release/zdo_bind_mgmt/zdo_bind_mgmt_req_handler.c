/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_bind_mgmt.o -> zdo_bind_mgmt_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_bind_mgmt_req_handler(void *arg)

{
  bool bVar1;
  uint16_t uVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined1 uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  undefined4 uVar9;
  zmsg_t *payload;
  uint16_t uStack_5e;
  undefined2 uStack_5c;
  uint16_t offset;
  ezb_address_t dst_addr;
  zdo_packet_t resp;
  zdp_bind_req_field_t req;
  
  memset((void *)((int)&dst_addr.u + 6),0,0x18);
  if (arg == (void *)0x0) {
    iVar6 = 0x80;
    goto _L0;
  }
  iVar6 = zdo_packet_response_init
                    ((undefined1 *)((int)&dst_addr.u + 6),arg,*(ushort *)((int)arg + 6) | 0x8000);
  if (iVar6 != 0) goto _L0;
  if (1 < *(ushort *)((int)arg + 6) - 0x21) goto _L0;
  memset(&resp.payload,0,0x18);
  payload = *(zmsg_t **)((int)arg + 0x14);
  _uStack_5c = 0;
  dst_addr._0_4_ = 0;
  dst_addr.u.group_addr.bcast = 0;
  if ((payload == (zmsg_t *)0x0) || (0xfff7 < *(ushort *)((int)arg + 2))) {
_L24:
    iVar6 = 0xfe;
  }
  else {
    uVar7 = zmsg_get_length(payload);
    iVar6 = zmsg_read_bytes(payload,0,8,&resp.payload);
    if (iVar6 == 0) {
      iVar6 = 0xffff;
    }
    uStack_5e = (uint16_t)iVar6;
    af_read_le8(payload,&uStack_5e,req.src_addr.field_0.u8 + 4);
    uVar2 = uStack_5e;
    iVar6 = zmsg_read_bytes(payload,uStack_5e,2,(undefined1 *)((int)&req.src_addr.field_0 + 6));
    if (iVar6 == 0) {
      uStack_5e = 0xffff;
    }
    else {
      uStack_5e = uVar2 + (short)iVar6;
    }
    af_read_le8(payload,&uStack_5e,&req.src_ep);
    uVar2 = uStack_5e;
    uVar4 = (uint)uStack_5e;
    if (uVar7 < uVar4) goto _L24;
    bVar1 = false;
    if (req.src_ep == '\x03') {
      iVar6 = zmsg_read_bytes(payload,uVar4,8,&req.cluster_id);
      if (iVar6 == 0) {
        uStack_5e = 0xffff;
      }
      else {
        uStack_5e = uVar2 + (short)iVar6;
      }
      af_read_le8(payload,&uStack_5e,(uint8_t *)((int)&req.dst_addr + 4));
    }
    else if (req.src_ep == '\x01') {
      iVar6 = zmsg_read_bytes(payload,uVar4,2,&req.cluster_id);
      if (iVar6 == 0) {
        uStack_5e = 0xffff;
      }
      else {
        uStack_5e = uVar2 + (short)iVar6;
      }
    }
    else {
      bVar1 = true;
    }
    if ((uVar7 < uStack_5e) || (bVar1)) goto _L24;
    iVar6 = nwk_get_extended_address();
    if (iVar6 == 0) {
_L0:
      iVar6 = 0x84;
    }
    else {
      piVar8 = (int *)nwk_get_extended_address();
      uVar3 = req.src_addr.field_0.u8[4];
      if ((resp.payload != (zdo_packet_payload_t *)*piVar8) ||
         (req.src_addr.field_0.u64._0_4_ != piVar8[1])) goto _L0;
      if ((byte)(req.src_addr.field_0.u8[4] - 1) < 0xfe) {
        if (req.src_ep == '\x03') {
          _uStack_5c = CONCAT31(stack0xffffffa5,3);
          memcpy(&offset,&req.cluster_id,8);
_L0:
          if (*(short *)((int)arg + 6) == 0x21) {
            aps_bind_table_add(&resp.payload,uVar3,req.src_addr.field_0.u64._6_2_,&stack0xffffffa4,
                               req.dst_addr._4_1_);
            uVar5 = ezb_err_to_zdp_status();
          }
          else {
            if (*(short *)((int)arg + 6) != 0x22) goto _L0;
            iVar6 = aps_bind_table_find_src(&resp.payload,uVar3,req.src_addr.field_0.u64._6_2_);
            if (iVar6 == 0) {
              uVar5 = 0x88;
            }
            else {
              aps_bind_table_remove
                        (&resp.payload,req.src_addr.field_0.u8[4],req.src_addr.field_0.u64._6_2_,
                         &stack0xffffffa4,req.dst_addr._4_1_);
              uVar5 = 0;
            }
          }
          if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) {
_L0:
            uVar9 = __assert_func(0,0,0,0);
            goto _L0;
          }
          uStack_5e = CONCAT11(uStack_5e._1_1_,uVar5);
          uVar9 = 1;
        }
        else {
          uVar9 = 1;
          if (req.src_ep == '\x01') {
            _uStack_5c = CONCAT31(stack0xffffffa5,1);
            _uStack_5c = CONCAT22(req.cluster_id,uStack_5c);
            dst_addr.addr_mode = req.dst_addr_mode;
            dst_addr._1_1_ = req._13_1_;
            goto _L0;
          }
          if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) goto _L0;
_L0:
          uStack_5e = CONCAT11(uStack_5e._1_1_,0x80);
        }
        iVar6 = zmsg_append_bytes(uVar9,&uStack_5e);
        if (iVar6 == 0) {
          iVar6 = zdo_packet_send((undefined1 *)((int)&dst_addr.u + 6));
          goto _L0;
        }
        iVar6 = 0x8a;
      }
      else {
        iVar6 = 0x82;
      }
    }
  }
  zdo_packet_free((undefined1 *)((int)&dst_addr.u + 6));
_L0:
  return (zdp_status_t)iVar6;
}


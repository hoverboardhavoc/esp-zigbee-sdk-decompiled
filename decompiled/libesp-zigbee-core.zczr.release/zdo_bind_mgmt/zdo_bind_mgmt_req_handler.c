/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
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
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  zmsg_t *payload;
  uint16_t uStack_5e;
  undefined2 uStack_5c;
  uint16_t offset;
  ezb_address_t dst_addr;
  zdo_packet_t resp;
  zdp_bind_req_field_t req;
  
  memset((void *)((int)&dst_addr.u + 6),0,0x18);
  if (arg == (void *)0x0) {
    iVar4 = 0x80;
    goto _L0;
  }
  iVar4 = zdo_packet_response_init
                    ((undefined1 *)((int)&dst_addr.u + 6),arg,*(ushort *)((int)arg + 6) | 0x8000);
  if (iVar4 != 0) goto _L0;
  if (*(ushort *)((int)arg + 6) - 0x21 < 2) {
    memset(&resp.payload,0,0x18);
    payload = *(zmsg_t **)((int)arg + 0x14);
    _uStack_5c = 0;
    dst_addr._0_4_ = 0;
    dst_addr.u.group_addr.bcast = 0;
    if ((payload != (zmsg_t *)0x0) && (*(ushort *)((int)arg + 2) < 0xfff8)) {
      uVar5 = zmsg_get_length(payload);
      iVar4 = zmsg_read_bytes(payload,0,8,&resp.payload);
      if (iVar4 == 0) {
        iVar4 = 0xffff;
      }
      uStack_5e = (uint16_t)iVar4;
      af_read_le8(payload,&uStack_5e,req.src_addr.field_0.u8 + 4);
      uVar2 = uStack_5e;
      iVar4 = zmsg_read_bytes(payload,uStack_5e,2,(undefined1 *)((int)&req.src_addr.field_0 + 6));
      if (iVar4 == 0) {
        uStack_5e = 0xffff;
      }
      else {
        uStack_5e = uVar2 + (short)iVar4;
      }
      af_read_le8(payload,&uStack_5e,&req.src_ep);
      uVar2 = uStack_5e;
      uVar3 = (uint)uStack_5e;
      if (uVar3 <= uVar5) {
        bVar1 = false;
        if (req.src_ep == '\x03') {
          iVar4 = zmsg_read_bytes(payload,uVar3,8,&req.cluster_id);
          if (iVar4 == 0) {
            uStack_5e = 0xffff;
          }
          else {
            uStack_5e = uVar2 + (short)iVar4;
          }
          af_read_le8(payload,&uStack_5e,(uint8_t *)((int)&req.dst_addr + 4));
        }
        else if (req.src_ep == '\x01') {
          iVar4 = zmsg_read_bytes(payload,uVar3,2,&req.cluster_id);
          if (iVar4 == 0) {
            uStack_5e = 0xffff;
          }
          else {
            uStack_5e = uVar2 + (short)iVar4;
          }
        }
        else {
          bVar1 = true;
        }
        if ((uStack_5e <= uVar5) && (!bVar1)) {
          iVar4 = nwk_get_extended_address();
          if (iVar4 == 0) goto _L0;
          piVar6 = (int *)nwk_get_extended_address();
          if (resp.payload != (zdo_packet_payload_t *)*piVar6) goto _L0;
          if (req.src_addr.field_0.u64._0_4_ != piVar6[1]) goto _L0;
          if ((byte)(req.src_addr.field_0.u8[4] - 1) < 0xfe) {
            if (req.src_ep == '\x03') {
              _uStack_5c = CONCAT31(stack0xffffffa5,3);
              memcpy(&offset,&req.cluster_id,8);
            }
            else {
              if (req.src_ep != '\x01') {
                iVar4 = 0x80;
                goto _L0;
              }
              _uStack_5c = CONCAT31(stack0xffffffa5,1);
              _uStack_5c = CONCAT22(req.cluster_id,uStack_5c);
              dst_addr.addr_mode = req.dst_addr_mode;
              dst_addr._1_1_ = req._13_1_;
            }
            if (*(short *)((int)arg + 6) == 0x21) {
              aps_bind_table_add(&resp.payload,req.src_addr.field_0.u8[4],
                                 req.src_addr.field_0.u64._6_2_,&stack0xffffffa4,req.dst_addr._4_1_)
              ;
              iVar4 = ezb_err_to_zdp_status();
              if (iVar4 == 0x8a) {
                iVar4 = 0x8c;
              }
              else if (iVar4 == 0xfe) goto _L0;
            }
            else {
              if (*(short *)((int)arg + 6) != 0x22) goto _L0;
              iVar7 = aps_bind_table_remove
                                (&resp.payload,req.src_addr.field_0.u8[4],
                                 req.src_addr.field_0.u64._6_2_,&stack0xffffffa4,req.dst_addr._4_1_)
              ;
              iVar4 = 0;
              if (iVar7 != 0) {
                iVar4 = 0x88;
              }
            }
          }
          else {
            iVar4 = 0x82;
          }
_L0:
          while (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) {
_L0:
            __assert_func(0,0,0,0);
_L0:
            iVar4 = 0x84;
          }
          uStack_5e = CONCAT11(uStack_5e._1_1_,(char)iVar4);
          iVar4 = zmsg_append_bytes(1,&uStack_5e);
          if (iVar4 == 0) {
            iVar4 = zdo_packet_send((undefined1 *)((int)&dst_addr.u + 6));
            goto _L0;
          }
          iVar4 = 0x8a;
          goto _L0;
        }
      }
    }
_L0:
    iVar4 = 0xfe;
  }
  else {
    iVar4 = 0x84;
  }
_L0:
  zdo_packet_free((undefined1 *)((int)&dst_addr.u + 6));
_L0:
  return (zdp_status_t)iVar4;
}


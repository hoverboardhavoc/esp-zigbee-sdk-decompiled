/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_leave_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_leave_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  ushort uVar1;
  bool bVar2;
  zdp_status_t zVar3;
  byte bVar4;
  _Bool _Var5;
  undefined3 extraout_var;
  uint uVar6;
  int *piVar7;
  undefined3 extraout_var_00;
  zdo_packet_user_ctx_t pvVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined3 extraout_var_01;
  bool bVar11;
  zdo_mgmt_req_user_ctx_t user_ctx;
  zdp_nwk_mgmt_leave_rsp_field_t rsp;
  zdp_nwk_mgmt_leave_req_field_t req;
  
  _rsp = 0;
  user_ctx.arg._0_1_ = 0;
  user_ctx.cb = (zdo_mgmt_user_callback_t)0x0;
  if (packet == (zdo_packet_t *)0x0) {
    uVar6 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    uVar6 = 0xfe;
  }
  else if (resp == (zdo_packet_t *)0x0) {
    uVar6 = 0xfe;
  }
  else {
    zVar3 = zdo_op_nwk_mgmt_leave_req(packet->payload,(zdp_nwk_mgmt_leave_req_field_t *)&rsp,false);
    if (CONCAT31(extraout_var,zVar3) == 0) {
      uVar1 = packet->src_addr;
      uVar6 = nwk_get_short_address();
      if (_rsp == 0) {
        bVar2 = true;
      }
      else {
        piVar7 = (int *)nwk_get_extended_address();
        if ((_rsp == *piVar7) && (piVar7[1] == 0)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
      }
      if (uVar1 == uVar6) {
        bVar11 = true;
      }
      else {
        iVar10 = nwk_validate_leave_request(packet->src_addr,packet->dst_addr,0);
        if (iVar10 == 0) {
          _Var5 = zdo_nwk_mgmt_leave_is_own_child((ezb_extaddr_t *)&rsp);
          if (CONCAT31(extraout_var_00,_Var5) == 0) {
            bVar11 = false;
          }
          else {
            bVar11 = true;
          }
        }
        else {
          bVar11 = true;
        }
      }
      if ((bVar2) && (bVar11)) {
        pvVar8 = (zdo_packet_user_ctx_t)zdo_create_mgmt_req(0x34);
        if (pvVar8 == (zdo_packet_user_ctx_t)0x0) {
          uVar6 = 0xfe;
        }
        else {
          puVar9 = (undefined1 *)zdo_mgmt_req_get_param();
          *puVar9 = (char)_rsp;
          puVar9[1] = (char)((uint)_rsp >> 8);
          puVar9[2] = (char)((uint)_rsp >> 0x10);
          puVar9[3] = (char)((uint)_rsp >> 0x18);
          puVar9[4] = 0;
          puVar9[5] = 0;
          puVar9[6] = 0;
          puVar9[7] = 0;
          iVar10 = zdo_mgmt_req_get_param(pvVar8);
          *(byte *)(iVar10 + 8) = *(byte *)(iVar10 + 8) & 0xfd;
          iVar10 = zdo_mgmt_req_get_param(pvVar8);
          *(byte *)(iVar10 + 8) = *(byte *)(iVar10 + 8) & 0xfe;
          zVar3 = zdo_op_nwk_mgmt_leave_rsp
                            (resp->payload,(zdp_nwk_mgmt_leave_rsp_field_t *)&user_ctx.arg,true);
          uVar6 = CONCAT31(extraout_var_01,zVar3);
          if (uVar6 == 0) {
            (resp->ctx).req_ctx.cb = zdo_mgmt_leave_rsp_confirm;
            (resp->ctx).req_ctx.arg = pvVar8;
            (resp->ctx).mode = '\0';
          }
        }
      }
      else {
        user_ctx.arg._0_1_ = 0x84;
        bVar4 = zdo_op_nwk_mgmt_leave_rsp
                          (resp->payload,(zdp_nwk_mgmt_leave_rsp_field_t *)&user_ctx.arg,true);
        uVar6 = (uint)bVar4;
      }
    }
    else {
      uVar6 = 0xfe;
    }
  }
  return (zdp_status_t)uVar6;
}


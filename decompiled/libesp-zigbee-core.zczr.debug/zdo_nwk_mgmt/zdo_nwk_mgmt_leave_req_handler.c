/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  _Bool _Var4;
  byte bVar5;
  undefined3 extraout_var;
  uint uVar6;
  int iVar7;
  zdo_packet_user_ctx_t pvVar8;
  undefined1 *puVar9;
  undefined3 extraout_var_00;
  int *piVar10;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  code *pcStack_38;
  zdo_mgmt_req_user_ctx_t user_ctx;
  zdp_nwk_mgmt_leave_rsp_field_t rsp;
  zdp_nwk_mgmt_leave_req_field_t req;
  
  _rsp = 0;
  user_ctx.arg._0_1_ = 0;
  pcStack_38 = (code *)0x0;
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
        piVar10 = (int *)nwk_get_extended_address();
        if ((_rsp == *piVar10) && (piVar10[1] == 0)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
      }
      if (((uVar1 == uVar6) ||
          (iVar7 = nwk_validate_leave_request(packet->src_addr,packet->dst_addr,0), iVar7 != 0)) ||
         (_Var4 = zdo_nwk_mgmt_leave_is_own_child((ezb_extaddr_t *)&rsp),
         CONCAT31(extraout_var_01,_Var4) != 0)) {
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
          iVar7 = zdo_mgmt_req_get_param(pvVar8);
          *(byte *)(iVar7 + 8) = *(byte *)(iVar7 + 8) & 0xfd;
          iVar7 = zdo_mgmt_req_get_param(pvVar8);
          *(byte *)(iVar7 + 8) = *(byte *)(iVar7 + 8) & 0xfe;
          if (bVar2) {
            zVar3 = zdo_op_nwk_mgmt_leave_rsp
                              (resp->payload,(zdp_nwk_mgmt_leave_rsp_field_t *)&user_ctx.arg,true);
            uVar6 = CONCAT31(extraout_var_02,zVar3);
            if (uVar6 == 0) {
              (resp->ctx).req_ctx.cb = zdo_mgmt_leave_rsp_confirm;
              (resp->ctx).req_ctx.arg = pvVar8;
              (resp->ctx).mode = '\0';
            }
          }
          else {
            zVar3 = zdo_op_nwk_mgmt_leave_rsp
                              (resp->payload,(zdp_nwk_mgmt_leave_rsp_field_t *)&user_ctx.arg,true);
            uVar6 = CONCAT31(extraout_var_00,zVar3);
            if (uVar6 == 0) {
              user_ctx.cb = (zdo_mgmt_user_callback_t)calloc(1,0x18);
              if (user_ctx.cb == (zdo_mgmt_user_callback_t)0x0) {
                uVar6 = 0x8a;
              }
              else {
                uVar6 = zdo_packet_move(resp);
                uVar6 = uVar6 & 0xff;
                if (uVar6 == 0) {
                  pcStack_38 = zdo_mgmt_leave_sync_rsp_cb;
                  zdo_mgmt_req_set_user_ctx(pvVar8,&pcStack_38);
                  zdo_send_mgmt_req(pvVar8,0);
                  uVar6 = 0xfe;
                }
                else {
                  mm_free(user_ctx.cb);
                }
              }
            }
          }
        }
      }
      else {
        user_ctx.arg._0_1_ = 0x84;
        bVar5 = zdo_op_nwk_mgmt_leave_rsp
                          (resp->payload,(zdp_nwk_mgmt_leave_rsp_field_t *)&user_ctx.arg,true);
        uVar6 = (uint)bVar5;
      }
    }
    else {
      uVar6 = 0xfe;
    }
  }
  return (zdp_status_t)uVar6;
}


/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_req_handler(void *arg)

{
  ushort uVar1;
  zdp_status_t zVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined1 auStack_28 [4];
  zdo_packet_t resp;
  
  auStack_28[0] = '\0';
  auStack_28[1] = 0;
  auStack_28._2_2_ = 0;
  resp.tsn = '\0';
  resp._1_1_ = 0;
  resp.dst_addr = 0;
  resp.src_addr = 0;
  resp.cluster_id = 0;
  resp.ctx.mode = '\0';
  resp.ctx._1_3_ = 0;
  resp.ctx.req_ctx.cb = (zdo_packet_req_callback_t)0x0;
  resp.ctx.req_ctx.arg = (zdo_packet_user_ctx_t)0x0;
  if (arg == (void *)0x0) {
    iVar3 = 0x80;
    goto _L0;
  }
  iVar3 = zdo_packet_response_init(auStack_28,arg,*(ushort *)((int)arg + 6) | 0x8000);
  if (iVar3 != 0) goto _L0;
  uVar1 = *(ushort *)((int)arg + 6);
  if (uVar1 == 0x34) {
    zVar2 = zdo_nwk_mgmt_leave_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
    iVar3 = CONCAT31(extraout_var_02,zVar2);
_L0:
    if (iVar3 == 0) {
      iVar3 = zdo_packet_send(auStack_28);
      goto _L0;
    }
  }
  else {
    if (uVar1 < 0x35) {
      if (uVar1 == 0x32) {
        zVar2 = zdo_nwk_mgmt_rtg_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
        iVar3 = CONCAT31(extraout_var_01,zVar2);
      }
      else if (uVar1 == 0x33) {
        zVar2 = zdo_nwk_mgmt_bind_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
        iVar3 = CONCAT31(extraout_var_04,zVar2);
      }
      else {
        if (uVar1 != 0x31) {
          iVar3 = 0x84;
          goto _L0;
        }
        zVar2 = zdo_nwk_mgmt_lqi_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
        iVar3 = CONCAT31(extraout_var,zVar2);
      }
      goto _L0;
    }
    if (uVar1 == 0x36) {
      zVar2 = zdo_nwk_mgmt_permit_joining_req_handler
                        ((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
      iVar3 = CONCAT31(extraout_var_03,zVar2);
      goto _L0;
    }
    if (uVar1 == 0x38) {
      zVar2 = zdo_nwk_mgmt_nwk_update_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
      iVar3 = CONCAT31(extraout_var_00,zVar2);
      goto _L0;
    }
    iVar3 = 0x84;
  }
_L0:
  zdo_packet_free(auStack_28);
_L0:
  return (zdp_status_t)iVar3;
}


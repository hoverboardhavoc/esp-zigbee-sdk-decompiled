/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_device_service_discovery_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_device_service_discovery_req_handler(void *arg)

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
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
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
  if (uVar1 == 5) {
    zVar2 = zdo_active_ep_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
    iVar3 = CONCAT31(extraout_var_05,zVar2);
_L0:
    if (iVar3 == 0) {
      iVar3 = zdo_packet_send(auStack_28);
      goto _L0;
    }
  }
  else {
    if (uVar1 < 6) {
      if (uVar1 == 2) {
        zVar2 = zdo_node_desc_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
        iVar3 = CONCAT31(extraout_var_07,zVar2);
      }
      else if (uVar1 < 3) {
        if (uVar1 == 0) {
          zVar2 = zdo_nwk_addr_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
          iVar3 = CONCAT31(extraout_var_03,zVar2);
        }
        else {
          if (uVar1 != 1) {
            iVar3 = 0x84;
            goto _L0;
          }
          zVar2 = zdo_ieee_addr_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
          iVar3 = CONCAT31(extraout_var,zVar2);
        }
      }
      else if (uVar1 == 3) {
        zVar2 = zdo_power_desc_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
        iVar3 = CONCAT31(extraout_var_06,zVar2);
      }
      else {
        if (uVar1 != 4) {
          iVar3 = 0x84;
          goto _L0;
        }
        zVar2 = zdo_simple_desc_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
        iVar3 = CONCAT31(extraout_var_00,zVar2);
      }
      goto _L0;
    }
    if (uVar1 == 0x15) {
      zVar2 = zdo_sys_srv_disc_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
      iVar3 = CONCAT31(extraout_var_08,zVar2);
      goto _L0;
    }
    if (uVar1 < 0x16) {
      if (uVar1 == 6) {
        zVar2 = zdo_match_desc_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
        iVar3 = CONCAT31(extraout_var_04,zVar2);
      }
      else {
        if (uVar1 != 0x13) {
          iVar3 = 0x84;
          goto _L0;
        }
        zVar2 = zdo_device_annce_handler((zdo_packet_t *)arg);
        iVar3 = CONCAT31(extraout_var_01,zVar2);
      }
      goto _L0;
    }
    if (uVar1 == 0x1f) {
      zVar2 = zdo_parent_annce_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
      iVar3 = CONCAT31(extraout_var_02,zVar2);
      goto _L0;
    }
    iVar3 = 0x84;
  }
_L0:
  zdo_packet_free(auStack_28);
_L0:
  return (zdp_status_t)iVar3;
}


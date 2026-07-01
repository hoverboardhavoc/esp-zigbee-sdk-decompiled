/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_packet_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ota_upgrade_packet_send(zcl_packet_t *packet)

{
  uint8_t ep_id;
  ota_upgrade_downloading_context_t *poVar1;
  zcl_attr_desc_t *pzVar2;
  undefined4 *puVar3;
  code *pcStack_18;
  zcl_packet_cnf_ctx_t cnf_ctx;
  
  if (packet == (zcl_packet_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",
                  0x16d,"ota_upgrade_packet_send","packet");
  }
  else {
    pcStack_18 = (code *)0x0;
    cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
    poVar1 = ota_upgrade_downloading_context_get((packet->header).src_ep);
    if (poVar1 != (ota_upgrade_downloading_context_t *)0x0) {
      pcStack_18 = ota_upgrade_packet_confirm_handler;
      cnf_ctx.cb = (ezb_af_user_cnf_callback_t)poVar1;
      zcl_packet_clone(&(poVar1->error).req.packet,packet);
      zcl_packet_send(packet,&pcStack_18);
      return;
    }
  }
  ep_id = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c"
                        ,0x171,"ota_upgrade_packet_send","context");
  pzVar2 = ota_upgrade_cli_get_attr_desc(ep_id,0xeff0);
  if (pzVar2 == (zcl_attr_desc_t *)0x0) {
    return;
  }
  puVar3 = (undefined4 *)calloc(1,0x74);
  pzVar2->data_p = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    return;
  }
  puVar3[10] = 0;
  puVar3[0xb] = 0;
  *(undefined2 *)((int)puVar3 + 0x32) = 0;
  *(undefined1 *)(puVar3 + 0xc) = 0x30;
  *(undefined1 *)((int)puVar3 + 0x31) = 3;
  puVar3[0xd] = 5000;
  *(undefined1 *)(puVar3 + 0xe) = 0;
  milli_timer_init(puVar3 + 0xf,ota_upgrade_download_retry,puVar3);
  pzVar2 = ota_upgrade_cli_get_attr_desc(ep_id,0);
  if (pzVar2 == (zcl_attr_desc_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",
                  0xa9,"ota_upgrade_downloading_context_init","attr_desc");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",
                  0xad,"ota_upgrade_downloading_context_init","attr_desc");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",
                  0xb8,"ota_upgrade_downloading_context_init","attr_desc");
  }
  else {
    *puVar3 = pzVar2->data_p;
    pzVar2 = ota_upgrade_cli_get_attr_desc(ep_id,1);
    if (pzVar2 == (zcl_attr_desc_t *)0x0) goto _L0;
    puVar3[1] = pzVar2->data_p;
    pzVar2 = ota_upgrade_cli_get_attr_desc(ep_id,2);
    if (pzVar2 != (zcl_attr_desc_t *)0x0) {
      pzVar2 = (zcl_attr_desc_t *)pzVar2->data_p;
    }
    puVar3[2] = pzVar2;
    pzVar2 = ota_upgrade_cli_get_attr_desc(ep_id,3);
    if (pzVar2 != (zcl_attr_desc_t *)0x0) {
      pzVar2 = (zcl_attr_desc_t *)pzVar2->data_p;
    }
    puVar3[3] = pzVar2;
    pzVar2 = ota_upgrade_cli_get_attr_desc(ep_id,4);
    if (pzVar2 != (zcl_attr_desc_t *)0x0) {
      pzVar2 = (zcl_attr_desc_t *)pzVar2->data_p;
    }
    puVar3[4] = pzVar2;
    pzVar2 = ota_upgrade_cli_get_attr_desc(ep_id,5);
    if (pzVar2 != (zcl_attr_desc_t *)0x0) {
      pzVar2 = (zcl_attr_desc_t *)pzVar2->data_p;
    }
    puVar3[5] = pzVar2;
    pzVar2 = ota_upgrade_cli_get_attr_desc(ep_id,6);
    if (pzVar2 == (zcl_attr_desc_t *)0x0) goto _L0;
    puVar3[6] = pzVar2->data_p;
    pzVar2 = ota_upgrade_cli_get_attr_desc(ep_id,7);
    if (pzVar2 != (zcl_attr_desc_t *)0x0) {
      puVar3[7] = pzVar2->data_p;
      pzVar2 = ota_upgrade_cli_get_attr_desc(ep_id,8);
      if (pzVar2 != (zcl_attr_desc_t *)0x0) {
        puVar3[8] = pzVar2->data_p;
        pzVar2 = ota_upgrade_cli_get_attr_desc(ep_id,9);
        if (pzVar2 != (zcl_attr_desc_t *)0x0) {
          pzVar2 = (zcl_attr_desc_t *)pzVar2->data_p;
        }
        puVar3[9] = pzVar2;
        return;
      }
      goto _L0;
    }
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",0xbb,
                "ota_upgrade_downloading_context_init","attr_desc");
_L0:
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",0xbe,
                "ota_upgrade_downloading_context_init","attr_desc");
  return;
}


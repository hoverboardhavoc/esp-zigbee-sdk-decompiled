/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_join_router.o -> touchlink_join_router_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_join_router_req_handler(touchlink_join_router_req_t *req)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint32_t unaff_s1;
  uint uVar5;
  uint8_t status;
  undefined1 uVar6;
  ezb_err_t eVar7;
  uint32_t uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  void *arg;
  
  if (req == (touchlink_join_router_req_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink_join_router.c",99,
                  "touchlink_join_router_req_handler",&_L0);
_L0:
    uVar8 = touchlink_transaction_id(0);
    if (unaff_s1 == uVar8) {
      iVar9 = touchlink_transaction_get();
      *(undefined1 *)(iVar9 + 0x60c) = 0xd;
      iVar9 = touchlink_transaction_get();
      *(undefined4 *)(iVar9 + 0x610) = 2;
      iVar9 = touchlink_transaction_get();
      uVar5 = touchlink_schedule_transaction_event(iVar9 + 0x60c);
      if (uVar5 == 0) {
        iVar9 = touchlink_transaction_get();
        *(undefined1 *)(iVar9 + 0x60c) = 5;
        iVar9 = touchlink_transaction_get();
        arg = (void *)(iVar9 + 0x610);
        *(undefined1 *)(iVar9 + 0x610) = 0;
        *(ezb_panid_t *)(iVar9 + 0x61a) = req->pan_id;
        *(uint8_t *)(iVar9 + 0x61c) = req->channel;
        *(ezb_shortaddr_t *)(iVar9 + 0x61e) = req->new_nwk_addr;
        uVar6 = touchlink_is_factory_new();
        *(undefined1 *)(iVar9 + 0x630) = uVar6;
        uVar10 = *(undefined4 *)&(req->ext_panid).field_0;
        puVar1 = (undefined4 *)((int)&(req->ext_panid).field_0 + 4);
        uVar3 = *(undefined2 *)puVar1;
        uVar4 = *puVar1;
        *(char *)(iVar9 + 0x611) = (char)*(undefined2 *)&(req->ext_panid).field_0;
        *(char *)(iVar9 + 0x612) = (char)((uint)uVar10 >> 8);
        *(char *)(iVar9 + 0x613) = (char)((uint)uVar10 >> 0x10);
        *(char *)(iVar9 + 0x614) = (char)((uint)uVar10 >> 0x18);
        *(char *)(iVar9 + 0x615) = (char)uVar3;
        *(char *)(iVar9 + 0x616) = (char)((uint)uVar4 >> 8);
        *(char *)(iVar9 + 0x617) = (char)((uint)uVar4 >> 0x10);
        *(char *)(iVar9 + 0x618) = (char)((uint)uVar4 >> 0x18);
        bVar2 = req->key_index;
        uVar10 = touchlink_transaction_id(0);
        iVar11 = touchlink_transaction_get();
        touchlink_decrypt_nwk_key
                  (req->encrypted_nwk_key,iVar9 + 0x620,1 << (bVar2 & 0x1f) & 0xffff,uVar10,
                   *(undefined4 *)(iVar11 + 4));
      }
      else {
        arg = (void *)0x0;
      }
      goto _L0;
    }
  }
  else {
    unaff_s1 = req->transaction_id;
    if (unaff_s1 != 0) goto _L0;
  }
  arg = (void *)0x0;
  uVar5 = 3;
_L0:
  status = touchlink_convert_status(uVar5 & 0xff);
  eVar7 = touchlink_send_join_router_rsp(status,(req->cmd_ctrl).tsn,arg);
  return eVar7;
}


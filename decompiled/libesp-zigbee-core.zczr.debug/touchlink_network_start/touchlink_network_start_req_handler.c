/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_network_start.o -> touchlink_network_start_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_network_start_req_handler(touchlink_network_start_req_t *req)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint32_t unaff_s1;
  ezb_err_t eVar5;
  undefined1 uVar6;
  uint32_t uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  
  if (req == (touchlink_network_start_req_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink_network_start.c",
                  0x77,"touchlink_network_start_req_handler",&_LC2);
_L0:
    uVar7 = touchlink_transaction_id(0);
    if (unaff_s1 == uVar7) {
      iVar8 = touchlink_transaction_get();
      *(undefined1 *)(iVar8 + 0x60c) = 0xd;
      iVar8 = touchlink_transaction_get();
      *(undefined4 *)(iVar8 + 0x610) = 1;
      iVar8 = touchlink_transaction_get();
      eVar5 = touchlink_schedule_transaction_event(iVar8 + 0x60c);
      if (eVar5 == 0) {
        iVar8 = touchlink_transaction_get();
        *(undefined1 *)(iVar8 + 0x60c) = 3;
        iVar8 = touchlink_transaction_get();
        *(undefined1 *)(iVar8 + 0x610) = 0;
        uVar6 = touchlink_is_factory_new();
        *(undefined1 *)(iVar8 + 0x630) = uVar6;
        *(uint8_t *)(iVar8 + 0x631) = (req->cmd_ctrl).tsn;
        *(ezb_panid_t *)(iVar8 + 0x61a) = req->pan_id;
        *(uint8_t *)(iVar8 + 0x61c) = req->channel;
        *(uint16_t *)(iVar8 + 0x61e) = req->nwk_addr;
        uVar9 = *(undefined4 *)&(req->ext_panid).field_0;
        puVar1 = (undefined4 *)((int)&(req->ext_panid).field_0 + 4);
        uVar3 = *(undefined2 *)puVar1;
        uVar4 = *puVar1;
        *(char *)(iVar8 + 0x611) = (char)*(undefined2 *)&(req->ext_panid).field_0;
        *(char *)(iVar8 + 0x612) = (char)((uint)uVar9 >> 8);
        *(char *)(iVar8 + 0x613) = (char)((uint)uVar9 >> 0x10);
        *(char *)(iVar8 + 0x614) = (char)((uint)uVar9 >> 0x18);
        *(char *)(iVar8 + 0x615) = (char)uVar3;
        *(char *)(iVar8 + 0x616) = (char)((uint)uVar4 >> 8);
        *(char *)(iVar8 + 0x617) = (char)((uint)uVar4 >> 0x10);
        *(char *)(iVar8 + 0x618) = (char)((uint)uVar4 >> 0x18);
        bVar2 = req->key_index;
        uVar9 = touchlink_transaction_id(0);
        iVar10 = touchlink_transaction_get();
        touchlink_decrypt_nwk_key
                  (req->encrypted_nwk_key,iVar8 + 0x620,1 << (bVar2 & 0x1f) & 0xffff,uVar9,
                   *(undefined4 *)(iVar10 + 4));
        iVar8 = touchlink_transaction_get();
        eVar5 = touchlink_schedule_transaction_event(iVar8 + 0x60c);
        if (eVar5 == 0) {
          return 0;
        }
      }
      goto _L0;
    }
  }
  else {
    unaff_s1 = req->transaction_id;
    if (unaff_s1 != 0) goto _L0;
  }
  eVar5 = 3;
_L0:
  touchlink_send_network_start_rsp_with_failure((req->cmd_ctrl).tsn);
  return eVar5;
}


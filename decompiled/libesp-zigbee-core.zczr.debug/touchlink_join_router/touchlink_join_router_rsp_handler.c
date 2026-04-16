/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_join_router.o -> touchlink_join_router_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_join_router_rsp_handler(touchlink_join_router_rsp_t *rsp)

{
  undefined4 uVar1;
  undefined3 uVar2;
  undefined4 uVar3;
  uint32_t uVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  uint32_t uVar7;
  ezb_err_t eVar8;
  int iVar9;
  undefined4 *puVar10;
  
  if (((rsp == (touchlink_join_router_rsp_t *)0x0) || (uVar4 = rsp->transaction_id, uVar4 == 0)) ||
     (uVar7 = touchlink_transaction_id(0), uVar4 != uVar7)) {
    eVar8 = 3;
  }
  else {
    iVar9 = touchlink_transaction_get();
    *(undefined1 *)(iVar9 + 0x60c) = 9;
    iVar9 = touchlink_transaction_get();
    *(uint8_t *)(iVar9 + 0x610) = rsp->status;
    uVar5 = touchlink_is_factory_new();
    *(undefined1 *)(iVar9 + 0x630) = uVar5;
    uVar6 = touchlink_pan_id();
    *(undefined2 *)(iVar9 + 0x61a) = uVar6;
    uVar5 = touchlink_current_channel();
    *(undefined1 *)(iVar9 + 0x61c) = uVar5;
    puVar10 = (undefined4 *)touchlink_extended_pan_id();
    uVar1 = *puVar10;
    uVar2 = *(undefined3 *)(puVar10 + 1);
    uVar3 = puVar10[1];
    *(char *)(iVar9 + 0x611) = (char)*(undefined3 *)puVar10;
    *(char *)(iVar9 + 0x612) = (char)((uint)uVar1 >> 8);
    *(char *)(iVar9 + 0x613) = (char)((uint)uVar1 >> 0x10);
    *(char *)(iVar9 + 0x614) = (char)((uint)uVar1 >> 0x18);
    *(char *)(iVar9 + 0x615) = (char)uVar2;
    *(char *)(iVar9 + 0x616) = (char)((uint)uVar3 >> 8);
    *(char *)(iVar9 + 0x617) = (char)((uint)uVar3 >> 0x10);
    *(char *)(iVar9 + 0x618) = (char)((uint)uVar3 >> 0x18);
    iVar9 = touchlink_transaction_get();
    eVar8 = touchlink_schedule_transaction_event(iVar9 + 0x60c);
  }
  return eVar8;
}


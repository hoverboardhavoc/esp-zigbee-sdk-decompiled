/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_network_start.o -> touchlink_network_start_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_network_start_rsp_handler(touchlink_network_start_rsp_t *rsp)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint32_t uVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  uint32_t uVar8;
  int iVar9;
  ezb_err_t eVar10;
  
  if (rsp == (touchlink_network_start_rsp_t *)0x0) {
    return 3;
  }
  uVar5 = rsp->transaction_id;
  if ((uVar5 != 0) && (uVar8 = touchlink_transaction_id(0), uVar5 == uVar8)) {
    iVar9 = touchlink_transaction_get();
    *(undefined1 *)(iVar9 + 0x60c) = 9;
    iVar9 = touchlink_transaction_get();
    *(uint8_t *)(iVar9 + 0x610) = rsp->status;
    uVar6 = touchlink_is_factory_new();
    *(undefined1 *)(iVar9 + 0x630) = uVar6;
    *(ezb_panid_t *)(iVar9 + 0x61a) = rsp->pan_id;
    *(uint8_t *)(iVar9 + 0x61c) = rsp->channel;
    uVar7 = touchlink_short_address();
    puVar1 = (undefined4 *)((int)&(rsp->ext_panid).field_0 + 4);
    uVar2 = *(undefined2 *)puVar1;
    uVar3 = *(undefined4 *)&(rsp->ext_panid).field_0;
    uVar4 = *puVar1;
    *(char *)(iVar9 + 0x611) = (char)*(undefined2 *)&(rsp->ext_panid).field_0;
    *(char *)(iVar9 + 0x612) = (char)((uint)uVar3 >> 8);
    *(char *)(iVar9 + 0x614) = (char)((uint)uVar3 >> 0x18);
    *(char *)(iVar9 + 0x616) = (char)((uint)uVar4 >> 8);
    *(undefined2 *)(iVar9 + 0x61e) = uVar7;
    *(char *)(iVar9 + 0x613) = (char)((uint)uVar3 >> 0x10);
    *(char *)(iVar9 + 0x615) = (char)uVar2;
    *(char *)(iVar9 + 0x617) = (char)((uint)uVar4 >> 0x10);
    *(char *)(iVar9 + 0x618) = (char)((uint)uVar4 >> 0x18);
    iVar9 = touchlink_transaction_get();
    eVar10 = touchlink_schedule_transaction_event(iVar9 + 0x60c);
    return eVar10;
  }
  return 3;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_secur.o -> apsme_verify_key_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void apsme_verify_key_indication(apsme_verify_key_ind_t *ind)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined2 uStack_24;
  undefined1 auStack_22 [2];
  zdo_app_signal_t app_signal;
  
  if (ind->key_type == '\x04') {
    memset(auStack_22,0,0x10);
    uStack_24 = 8;
    puVar5 = (undefined1 *)zdo_app_signal_get_params(&uStack_24);
    puVar1 = (undefined4 *)((int)&(ind->src_address).field_0 + 4);
    uVar2 = *(undefined2 *)puVar1;
    uVar3 = *(undefined4 *)&(ind->src_address).field_0;
    uVar4 = *puVar1;
    *puVar5 = (char)*(undefined2 *)&(ind->src_address).field_0;
    puVar5[1] = (char)((uint)uVar3 >> 8);
    puVar5[3] = (char)((uint)uVar3 >> 0x18);
    puVar5[5] = (char)((uint)uVar4 >> 8);
    puVar5[7] = (char)((uint)uVar4 >> 0x18);
    puVar5[2] = (char)((uint)uVar3 >> 0x10);
    puVar5[4] = (char)uVar2;
    puVar5[6] = (char)((uint)uVar4 >> 0x10);
    *(undefined2 *)(puVar5 + 8) = 0xffff;
    nwk_address_short_by_extended(ind,puVar5 + 8);
    *(undefined2 *)(puVar5 + 10) = 1;
    zdo_app_put_signal(&uStack_24);
    return;
  }
  return;
}


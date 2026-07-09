/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_secur.o -> apsme_verify_key_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void apsme_verify_key_indication(undefined4 *param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined2 uStack_24;
  undefined1 auStack_22 [22];
  
  if (*(char *)(param_1 + 2) == '\x04') {
    memset(auStack_22,0,0x10);
    uStack_24 = 8;
    puVar4 = (undefined1 *)zdo_app_signal_get_params(&uStack_24);
    uVar1 = *(undefined2 *)(param_1 + 1);
    uVar2 = *param_1;
    uVar3 = param_1[1];
    *puVar4 = (char)*(undefined2 *)param_1;
    puVar4[1] = (char)((uint)uVar2 >> 8);
    puVar4[3] = (char)((uint)uVar2 >> 0x18);
    puVar4[5] = (char)((uint)uVar3 >> 8);
    puVar4[7] = (char)((uint)uVar3 >> 0x18);
    puVar4[2] = (char)((uint)uVar2 >> 0x10);
    puVar4[4] = (char)uVar1;
    puVar4[6] = (char)((uint)uVar3 >> 0x10);
    *(undefined2 *)(puVar4 + 8) = 0xffff;
    nwk_address_short_by_extended(param_1,puVar4 + 8);
    *(undefined2 *)(puVar4 + 10) = 1;
    zdo_app_put_signal(&uStack_24);
    return;
  }
  return;
}


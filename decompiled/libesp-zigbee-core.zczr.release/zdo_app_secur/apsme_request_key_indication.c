/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_secur.o -> apsme_request_key_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void apsme_request_key_indication(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 uStack_34;
  undefined1 auStack_33 [35];
  
  if (*(char *)(param_1 + 2) == '\x04') {
    iVar1 = core_globals_get();
    if (((((*(ushort *)(iVar1 + 0x9bc) & 0x18) != 0) &&
         (iVar1 = aps_secur_key_pair_find_or_create(param_1), iVar1 != 0)) &&
        ((*(ushort *)(iVar1 + 0x34) & 6) != 2)) &&
       ((iVar2 = core_globals_get(), (*(ushort *)(iVar2 + 0x9bc) & 0x18) == 8 ||
        ((*(ushort *)(iVar1 + 0x34) & 6) == 0)))) {
      memset(&uStack_3c,0,0x2a);
      uStack_34 = 4;
      random_crypto_fill_buffer(auStack_33,0x10);
      uStack_3c = *param_1;
      uStack_38 = param_1[1];
      apsme_transport_key_request(&uStack_3c);
    }
    return;
  }
  return;
}


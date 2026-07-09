/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_tc.o -> apsme_update_device_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void apsme_update_device_indication(undefined4 *param_1)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  int iVar7;
  void *__src;
  undefined1 uVar8;
  undefined2 local_50;
  undefined1 auStack_4e [18];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 uStack_34;
  undefined1 auStack_33 [16];
  undefined1 uStack_23;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  
  memset(&uStack_3c,0,0x2a);
  cVar1 = *(char *)((int)param_1 + 0x12);
  if (cVar1 == '\x02') {
    aps_forget_device(*(undefined2 *)(param_1 + 4),param_1 + 2);
_L0:
    uVar8 = 0;
  }
  else {
    if (cVar1 == '\x03') {
      iVar7 = aps_secur_is_centralized();
      if (iVar7 != 0) goto _L0;
    }
    else {
      if (cVar1 != '\x01') goto _L0;
_L0:
      iVar7 = aps_secur_key_pair_find_or_create(param_1 + 2);
      if ((iVar7 != 0) && ((*(ushort *)(iVar7 + 0x34) & 6) != 2)) {
        iVar7 = aps_secur_tc_setup_key_pair();
        uVar8 = 1;
        if (iVar7 != 0) goto _L0;
        uStack_34 = 1;
        uStack_1a = *(undefined2 *)param_1;
        uStack_16 = *(undefined2 *)(param_1 + 1);
        uStack_18 = (undefined2)((uint)*param_1 >> 0x10);
        uStack_14 = (undefined2)((uint)param_1[1] >> 0x10);
        uStack_3c = param_1[2];
        uStack_38 = param_1[3];
        uStack_23 = nwk_secur_get_current_key_seq();
        __src = (void *)nwk_secur_get_key_by_seq();
        memcpy(auStack_33,__src,0x10);
        iVar7 = apsme_transport_key_request(&uStack_3c);
        if (iVar7 == 0) goto _L0;
        log_write(2,"zdo_app_tc.c","TransportKey failed(0x%x)",iVar7);
      }
    }
    uVar8 = 2;
  }
_L0:
  memset(auStack_4e,0,0x10);
  local_50 = 7;
  puVar6 = (undefined1 *)zdo_app_signal_get_params(&local_50);
  uVar3 = *(undefined2 *)(param_1 + 3);
  uVar4 = param_1[2];
  uVar5 = param_1[3];
  *puVar6 = (char)*(undefined2 *)(param_1 + 2);
  puVar6[1] = (char)((uint)uVar4 >> 8);
  puVar6[3] = (char)((uint)uVar4 >> 0x18);
  puVar6[5] = (char)((uint)uVar5 >> 8);
  puVar6[7] = (char)((uint)uVar5 >> 0x18);
  uVar2 = *(undefined2 *)(param_1 + 4);
  puVar6[2] = (char)((uint)uVar4 >> 0x10);
  puVar6[4] = (char)uVar3;
  puVar6[6] = (char)((uint)uVar5 >> 0x10);
  *(undefined2 *)(puVar6 + 8) = uVar2;
  puVar6[10] = *(undefined1 *)((int)param_1 + 0x12);
  *(undefined2 *)(puVar6 + 0xc) = 0xffff;
  nwk_address_short_by_extended(param_1,puVar6 + 0xc);
  puVar6[0xb] = uVar8;
  zdo_app_put_signal(&local_50);
  return;
}


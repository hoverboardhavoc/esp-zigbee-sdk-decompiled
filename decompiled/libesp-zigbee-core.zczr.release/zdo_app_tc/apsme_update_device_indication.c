/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_tc.o -> apsme_update_device_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void apsme_update_device_indication(undefined4 *param_1)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  void *__src;
  int iVar7;
  undefined1 *puVar8;
  ushort uVar9;
  undefined1 uVar10;
  undefined2 uStack_52;
  undefined2 uStack_50;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
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
  bVar1 = *(byte *)((int)param_1 + 0x12);
  if (bVar1 == 2) {
    aps_forget_device(*(undefined2 *)(param_1 + 4),param_1 + 2);
  }
  else if (bVar1 < 3) {
    if (bVar1 == 0) {
      uStack_52 = 0;
      iVar6 = nwk_address_update(param_1 + 2,*(undefined2 *)(param_1 + 4),&uStack_52);
      if (iVar6 == 0xd) {
        uStack_50 = CONCAT11((char)*(undefined2 *)(param_1 + 4),0xd);
        uStack_4d = 0;
        uStack_4e = (undefined1)((ushort)*(undefined2 *)(param_1 + 4) >> 8);
        nwk_send_status(0xfffd,&uStack_50);
        nwk_handle_network_status_local(&uStack_50);
      }
    }
    else {
_L0:
      iVar6 = aps_secur_key_pair_find_or_create(param_1 + 2);
      if ((iVar6 == 0) || ((*(ushort *)(iVar6 + 0x34) & 6) == 2)) goto _L0;
      if (*(char *)((int)param_1 + 0x12) == '\x01') {
_L0:
        iVar6 = aps_secur_tc_setup_key_pair(iVar6);
        if (iVar6 != 0) {
_L0:
          uVar10 = 1;
          goto _L0;
        }
      }
      else {
        iVar7 = aps_secur_tcpol_get_allow_rejoins_with_well_known_key();
        uVar9 = *(ushort *)(iVar6 + 0x34) & 6;
        if (iVar7 == 0) {
          if (uVar9 != 4) goto _L0;
        }
        else if (uVar9 != 4) goto _L0;
      }
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
      iVar6 = apsme_transport_key_request(&uStack_3c);
      if (iVar6 != 0) {
        log_write(2,"zdo_app_tc.c","TransportKey failed(0x%x)",iVar6);
        goto _L0;
      }
    }
  }
  else if (bVar1 == 3) {
    iVar6 = aps_secur_is_centralized();
    if (iVar6 != 0) goto _L0;
_L0:
    uVar10 = 2;
    goto _L0;
  }
  uVar10 = 0;
_L0:
  memset(&uStack_4e,0,0x10);
  uStack_50 = 7;
  puVar8 = (undefined1 *)zdo_app_signal_get_params(&uStack_50);
  uVar3 = *(undefined2 *)(param_1 + 3);
  uVar4 = param_1[2];
  uVar5 = param_1[3];
  *puVar8 = (char)*(undefined2 *)(param_1 + 2);
  puVar8[1] = (char)((uint)uVar4 >> 8);
  puVar8[3] = (char)((uint)uVar4 >> 0x18);
  puVar8[5] = (char)((uint)uVar5 >> 8);
  puVar8[7] = (char)((uint)uVar5 >> 0x18);
  uVar2 = *(undefined2 *)(param_1 + 4);
  puVar8[2] = (char)((uint)uVar4 >> 0x10);
  puVar8[4] = (char)uVar3;
  puVar8[6] = (char)((uint)uVar5 >> 0x10);
  *(undefined2 *)(puVar8 + 8) = uVar2;
  puVar8[10] = *(undefined1 *)((int)param_1 + 0x12);
  *(undefined2 *)(puVar8 + 0xc) = 0xffff;
  nwk_address_short_by_extended(param_1,puVar8 + 0xc);
  puVar8[0xb] = uVar10;
  zdo_app_put_signal(&uStack_50);
  return;
}


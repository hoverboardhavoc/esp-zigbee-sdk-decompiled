/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_core.o -> zcl_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_indication_handler(size_t param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  size_t __size;
  undefined4 uVar4;
  undefined1 *puStack_50;
  ushort uStack_4c;
  undefined1 *puStack_48;
  undefined2 uStack_44;
  void *pvStack_40;
  byte bStack_3c;
  undefined1 auStack_38 [36];
  undefined4 uStack_14;
  
  memset(auStack_38,0,0x28);
  if (param_1 != 0) goto _L0;
  do {
    do {
      __assert_func(0,0,0,0);
_L0:
      iVar2 = zcl_packet_init_with_msg(auStack_38,param_1);
      if (iVar2 != 0) goto _L0;
      iVar2 = core_globals_get();
      param_1 = 0x1000;
      if (*(int *)(iVar2 + 0xd18) == 0) goto _L0;
      iVar2 = core_globals_get();
    } while (*(int *)(iVar2 + 0xd18) == 0);
    puStack_50 = auStack_38;
    param_1 = zmsg_get_length(uStack_14);
    uStack_4c = (ushort)param_1;
    puStack_48 = (undefined1 *)calloc(1,param_1);
    if ((puStack_48 == (undefined1 *)0x0) && (param_1 != 0)) {
      iVar2 = 1;
      goto _L0;
    }
    uVar3 = zmsg_read_bytes(uStack_14,0,param_1,puStack_48);
    if (uVar3 == 0) {
      bVar1 = param_1 != 0;
      param_1 = -(uint)bVar1;
      uVar3 = (uint)bVar1 * -0x10000 >> 0x10;
    }
  } while (uStack_4c != uVar3);
  iVar2 = core_globals_get();
  iVar2 = (**(code **)(iVar2 + 0xd18))(&puStack_50,*(code **)(iVar2 + 0xd18));
_L0:
  if (puStack_48 != (undefined1 *)0x0) {
    mm_free();
  }
  if (iVar2 != 0) {
    return 0;
  }
_L0:
  uVar3 = zcl_packet_is_acceptable(auStack_38);
  if (uVar3 != 0) goto _L0;
  iVar2 = zcl_packet_is_general(auStack_38);
  if (iVar2 == 0) {
    iVar2 = zcl_packet_is_manuf_spec(auStack_38);
    if (iVar2 == 0) {
      uVar3 = zcl_cluster_cmd_handler(auStack_38);
    }
    else {
      memset(&puStack_50,0,0x18);
      uVar3 = zcl_packet_to_message(&puStack_50,auStack_38);
      if (uVar3 == 0) {
        puStack_48 = auStack_38;
        __size = zcl_packet_payload_get_length(uStack_14);
        uStack_44 = (undefined2)__size;
        pvStack_40 = calloc(1,__size);
        if (pvStack_40 == (void *)0x0) {
          uVar3 = 0x89;
          if (__size != 0) goto _L0;
_L0:
          pvStack_40 = (void *)0x0;
        }
        else if (__size == 0) goto _L0;
        zmsg_read_bytes(uStack_14,0,pvStack_40);
        bStack_3c = 0xfe;
        zcl_core_action_schedule(9,&puStack_50);
        uVar3 = (uint)bStack_3c;
        if (uVar3 == 0xfe) {
          uVar3 = 0;
        }
        zcl_packet_send_default_response(auStack_38,uVar3);
      }
_L0:
      if (pvStack_40 != (void *)0x0) {
        mm_free();
      }
    }
  }
  else {
    uVar3 = zcl_general_cmd_handler(auStack_38);
  }
  if (uVar3 == 0) {
    return 0;
  }
_L0:
  if (uVar3 == 0xfe) {
_L0:
    uVar4 = 0xfe;
  }
  else {
    uVar4 = zcl_packet_send_default_response(auStack_38,uVar3);
  }
  return uVar4;
}


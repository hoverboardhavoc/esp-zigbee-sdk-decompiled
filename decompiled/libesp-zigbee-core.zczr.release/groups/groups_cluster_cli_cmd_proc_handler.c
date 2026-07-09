/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> groups.o -> groups_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int groups_cluster_cli_cmd_proc_handler(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  void *pvVar8;
  uint __nmemb;
  uint uStack_74;
  undefined1 uStack_65;
  ushort uStack_64;
  ushort uStack_62;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  int iStack_58;
  undefined4 uStack_54;
  void *pvStack_50;
  byte bStack_4c;
  undefined1 auStack_48 [48];
  
  memset(auStack_48,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
    return 1;
  }
  iVar5 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar5 != 0) {
    return iVar5;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  if (bVar1 == 2) {
    uStack_62 = 0;
    uStack_65 = 0;
    uStack_64 = uStack_64 & 0xff00;
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_62,&uStack_65);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_62,&uStack_64);
    __nmemb = (uint)(byte)uStack_64;
    pvVar8 = calloc(__nmemb,2);
    uVar6 = 0;
    if ((__nmemb == 0) || (uStack_74 = 0x89, pvVar8 != (void *)0x0)) {
      while( true ) {
        if ((byte)uStack_64 <= uVar6) break;
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_62,
                            (void *)(uVar6 * 2 + (int)pvVar8));
        uVar6 = uVar6 + 1 & 0xff;
      }
      uVar6 = zmsg_get_length();
      uVar2 = uStack_65;
      uStack_74 = 0x80;
      if (uStack_62 <= uVar6) {
        uVar3 = (byte)uStack_64;
        memset(&uStack_60,0,0x18);
        uStack_74 = zcl_packet_to_message(&uStack_60,param_1);
        if (uStack_74 == 0) {
          bStack_4c = 0xfe;
          uStack_54._0_2_ = CONCAT11(uVar3,uVar2);
          iStack_58 = param_1;
          pvStack_50 = pvVar8;
          zcl_core_action_schedule(0x10,&uStack_60);
          if (bStack_4c != 0xfe) {
            uStack_74 = (uint)bStack_4c;
          }
        }
      }
      if (pvVar8 != (void *)0x0) {
        mm_free(pvVar8);
      }
    }
    goto _L0;
  }
  if (bVar1 < 3) {
    if (bVar1 == 0) {
      uStack_62 = 0xffff;
      uStack_64 = 0;
      uStack_65 = 0;
      af_read_le8_isra_0(&uStack_64,&uStack_65);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_62);
      uVar6 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      uVar4 = uStack_62;
      uVar2 = uStack_65;
      uStack_74 = 0x80;
      if (uVar6 < uStack_64) goto _L0;
      uStack_60 = 0;
      uStack_5c = 0;
      iStack_58 = 0;
      uStack_54 = 0;
      pvStack_50 = (void *)0x0;
      uStack_74 = zcl_packet_to_message(&uStack_60,param_1,0x80);
      if (uStack_74 != 0) goto _L0;
      uStack_54 = CONCAT31(uStack_54._1_3_,uVar2);
      uStack_54 = CONCAT22(uVar4,(undefined2)uStack_54);
      uVar7 = 0xe;
      goto _L0;
    }
    uStack_62 = 0xffff;
    uStack_64 = 0;
    uStack_65 = 0;
    uVar6 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_65);
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_62);
    uVar4 = uStack_62;
    uVar2 = uStack_65;
    uStack_74 = 0x80;
    if (uVar6 < uStack_64) goto _L0;
    memset(&uStack_60,0,0x18);
    uStack_74 = zcl_packet_to_message(&uStack_60,param_1);
    if (uStack_74 != 0) goto _L0;
    bStack_4c = 0xfe;
    uStack_54 = CONCAT31(uStack_54._1_3_,uVar2);
    uStack_54 = CONCAT22(uVar4,(undefined2)uStack_54);
    pvStack_50 = (void *)0x0;
    iStack_58 = param_1;
    zcl_core_action_schedule(0xf,&uStack_60,0);
    bVar1 = bStack_4c;
  }
  else {
    if (bVar1 != 3) {
      uStack_74 = 0x81;
      goto _L0;
    }
    uStack_62 = 0xffff;
    uStack_64 = 0;
    uStack_65 = 0;
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_65);
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_62);
    uVar6 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar4 = uStack_62;
    uVar2 = uStack_65;
    uStack_74 = 0x80;
    if (uVar6 < uStack_64) goto _L0;
    uStack_60 = 0;
    uStack_5c = 0;
    iStack_58 = 0;
    uStack_54 = 0;
    pvStack_50 = (void *)0x0;
    uStack_74 = zcl_packet_to_message(&uStack_60,param_1,0x80);
    if (uStack_74 != 0) goto _L0;
    uStack_54 = CONCAT31(uStack_54._1_3_,uVar2);
    uStack_54 = CONCAT22(uVar4,(undefined2)uStack_54);
    uVar7 = 0x11;
_L0:
    pvStack_50 = (void *)CONCAT31(pvStack_50._1_3_,0xfe);
    iStack_58 = param_1;
    zcl_core_action_schedule(uVar7,&uStack_60,uStack_74);
    bVar1 = (byte)pvStack_50;
  }
  if (bVar1 != 0xfe) {
    uStack_74 = (uint)bVar1;
  }
_L0:
  iVar5 = zcl_packet_setup_default_response(auStack_48,param_1,uStack_74);
  if (iVar5 == 0) {
    zcl_packet_send(auStack_48,0);
  }
  else {
    zcl_packet_free(auStack_48);
  }
  return iVar5;
}


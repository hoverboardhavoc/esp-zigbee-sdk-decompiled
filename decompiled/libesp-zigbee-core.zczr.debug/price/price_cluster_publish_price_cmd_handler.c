/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> price.o -> price_cluster_publish_price_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 price_cluster_publish_price_cmd_handler(int param_1,int param_2)

{
  byte bVar1;
  ushort *unaff_s1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uStack_7c;
  undefined2 uStack_76;
  uint uStack_74;
  byte bStack_6f;
  ushort uStack_6e;
  undefined1 auStack_6c [8];
  int iStack_64;
  uint uStack_60;
  byte local_5c;
  undefined1 auStack_5b [11];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  byte bStack_48;
  undefined1 uStack_47;
  undefined2 uStack_46;
  ushort uStack_44;
  undefined2 uStack_42;
  undefined2 uStack_40;
  undefined2 uStack_3e;
  uint uStack_3c;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined2 uStack_32;
  undefined2 uStack_30;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined1 uStack_2c;
  byte bStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 auStack_26 [2];
  byte bStack_24;
  
  memset(auStack_6c,0,0x4c);
  uStack_6e = 0;
  bStack_6f = 0;
  uStack_74 = 0;
  uStack_76 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/price.c",0xcd,
                  "price_cluster_publish_price_cmd_handler","packet && rsp");
  }
  else {
    unaff_s1 = &uStack_6e;
    af_read_le32(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_74);
    uStack_60 = uStack_74;
    iVar3 = af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,&local_5c);
    if (iVar3 == 0) {
      uVar2 = 0x80;
      goto _L0;
    }
    if (0xc < local_5c) {
      uVar2 = 0x87;
      goto _L0;
    }
  }
  af_read_bytes(*(undefined4 *)(param_1 + 0x24),unaff_s1,auStack_5b);
  af_read_le32(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_74);
  uStack_50 = CONCAT13((char)(uStack_74 >> 0x10),
                       CONCAT12((char)(uStack_74 >> 8),
                                CONCAT11((char)uStack_74,(undefined1)uStack_50)));
  uStack_4c = CONCAT31(uStack_4c._1_3_,(char)(uStack_74 >> 0x18));
  af_read_le32(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_74);
  uStack_4c = CONCAT13((char)(uStack_74 >> 0x10),
                       CONCAT12((char)(uStack_74 >> 8),
                                CONCAT11((char)uStack_74,(undefined1)uStack_4c)));
  bStack_48 = (byte)(uStack_74 >> 0x18);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_47);
  af_read_le16(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_76);
  uStack_46 = uStack_76;
  af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,&bStack_6f);
  uStack_44 = (ushort)((bStack_6f & 0xf) << 4) | uStack_44 & 0xff00 | (ushort)(bStack_6f >> 4);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,&bStack_6f);
  uStack_44 = (ushort)((bStack_6f & 0xf) << 0xc) | uStack_44 & 0xff | (ushort)(bStack_6f >> 4) << 8;
  af_read_le32(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_74);
  uStack_42 = (undefined2)uStack_74;
  uStack_40 = (undefined2)(uStack_74 >> 0x10);
  af_read_le16(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_76);
  uStack_3e = uStack_76;
  af_read_le32(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_74);
  uStack_3c = uStack_74;
  af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_38);
  af_read_le32(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_74);
  uStack_37 = (undefined1)uStack_74;
  uStack_36 = (undefined1)(uStack_74 >> 8);
  uStack_35 = (undefined1)(uStack_74 >> 0x10);
  uStack_34 = (undefined1)(uStack_74 >> 0x18);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_33);
  af_read_le32(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_74);
  uStack_32 = (undefined2)uStack_74;
  uStack_30 = (undefined2)(uStack_74 >> 0x10);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_2e);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_2d);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_2c);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,&bStack_2b);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_2a);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_29);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_28);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,&uStack_27);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),unaff_s1,auStack_26);
  uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uVar2 < uStack_6e) {
    uVar2 = 0x80;
  }
  else {
    uVar2 = zcl_packet_to_message(auStack_6c,param_1);
    if (uVar2 == 0) {
      bStack_24 = 0xfe;
      iStack_64 = param_1;
      zcl_core_action_schedule(0x4f,auStack_6c);
      uVar2 = (uint)bStack_24;
      if (uVar2 == 0xfe) {
        uVar2 = 1;
      }
      else {
        bVar1 = bStack_2b & 1;
        if ((bStack_2b & 1) != 0) {
          uStack_7c = uStack_60;
          iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_7c);
          if (iVar3 != 0) {
            uVar2 = 0x89;
            goto _L0;
          }
          uStack_7c = uStack_4c << 0x18 | uStack_50 >> 8;
          iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_7c);
          if (iVar3 != 0) {
            uVar2 = 0x89;
            goto _L0;
          }
          uStack_7c = zcl_time_get_utc_time(*(undefined1 *)(param_1 + 0x15));
          if (uStack_7c == 0xffffffff) {
            uStack_7c = (uint)bStack_48 << 0x18 | uStack_4c >> 8;
          }
          iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_7c);
          if (iVar3 != 0) {
            uVar2 = 0x89;
            goto _L0;
          }
          uStack_7c = CONCAT31(uStack_7c._1_3_,bStack_2b);
          iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_7c);
          if (iVar3 != 0) {
            uVar2 = 0x89;
            goto _L0;
          }
          uVar2 = zcl_packet_setup_response(param_2,param_1,2);
        }
        if ((uVar2 == 0) && (bVar1 != 0)) {
          return 0;
        }
      }
    }
  }
_L0:
  uVar4 = zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return uVar4;
}


#ifndef LVTABLE_H
#define LVTABLE_H

#include <core/lvobject.hpp>
#include <lvgl/lv_objx/lv_table.h>

class LVTable : public LVObject
{
    LV_OBJECT
public:

    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a table object
    * @param par pointer to an object, it will be the parent of the new table
    * @param copy pointer to a table object, if not NULL then the new object will be copied from it
    * @return pointer to the created table
    */
    DEFINE_CONSTRUCTOR(LVTable,lv_table_create,LVObject)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set the value of a cell.
    * @param table pointer to a Table object
    * @param row id of the row [0 .. row_cnt -1]
    * @param col id of the column [0 .. col_cnt -1]
    * @param txt text to display in the cell. It will be copied and saved so this variable is not required after this function call.
    */
    void setCellValue(uint16_t row, uint16_t col, const char * txt)
    {
        lv_table_set_cell_value(m_this, row, col, txt);
    }

    /**
    * Set the number of rows
    * @param table table pointer to a Table object
    * @param row_cnt number of rows
    */
    void setRowsCount( uint16_t row_cnt)
    {
        lv_table_set_row_cnt(m_this, row_cnt);
    }

    /**
    * Set the number of columns
    * @param table table pointer to a Table object
    * @param col_cnt number of columns. Must be < LV_TABLE_COL_MAX
    */
    void setColumnsCount(uint16_t col_cnt)
    {
        lv_table_set_col_cnt(m_this, col_cnt);
    }

    /**
    * Set the width of a column
    * @param table table pointer to a Table object
    * @param col_id id of the column [0 .. LV_TABLE_COL_MAX -1]
    * @param w width of the column
    */
    void setColumnWidth(uint16_t col_id, lv_coord_t w)
    {
        lv_table_set_col_width(m_this, col_id, w);
    }

    /**
    * Set the text align in a cell
    * @param table pointer to a Table object
    * @param row id of the row [0 .. row_cnt -1]
    * @param col id of the column [0 .. col_cnt -1]
    * @param align LV_LABEL_ALIGN_LEFT or LV_LABEL_ALIGN_CENTER or LV_LABEL_ALIGN_RIGHT
    */
    void setCellAlign(uint16_t row, uint16_t col, lv_label_align_t align)
    {
        lv_table_set_cell_align(m_this, row, col, align);
    }

    /**
    * Set the type of a cell.
    * @param table pointer to a Table object
    * @param row id of the row [0 .. row_cnt -1]
    * @param col id of the column [0 .. col_cnt -1]
    * @param type 1,2,3 or 4. The cell style will be chosen accordingly.
    */
    void setCellType(uint16_t row, uint16_t col, uint8_t type)
    {
        lv_table_set_cell_type(m_this, row, col, type);
    }

    /**
    * Set the cell crop. (Don't adjust the height of the cell according to its content)
    * @param table pointer to a Table object
    * @param row id of the row [0 .. row_cnt -1]
    * @param col id of the column [0 .. col_cnt -1]
    * @param crop true: crop the cell content; false: set the cell height to the content.
    */
    void setCellCrop(uint16_t row, uint16_t col, bool crop)
    {
        lv_table_set_cell_crop(m_this, row, col, crop);
    }

    /**
    * Merge a cell with the right neighbor. The value of the cell to the right won't be displayed.
    * @param table table pointer to a Table object
    * @param row id of the row [0 .. row_cnt -1]
    * @param col id of the column [0 .. col_cnt -1]
    * @param en true: merge right; false: don't merge right
    */
    void setCellMergeRight(uint16_t row, uint16_t col, bool en)
    {
        lv_table_set_cell_merge_right(m_this, row, col, en);
    }

    /**
    * Set a style of a table.
    * @param table pointer to table object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_table_style_t type, lv_style_t * style)
    {
        lv_table_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the value of a cell.
    * @param table pointer to a Table object
    * @param row id of the row [0 .. row_cnt -1]
    * @param col id of the column [0 .. col_cnt -1]
    * @return text in the cell
    */
    const char * getCellValue(uint16_t row, uint16_t col)
    {
        return lv_table_get_cell_value(m_this, row, col);
    }

    /**
    * Get the number of rows.
    * @param table table pointer to a Table object
    * @return number of rows.
    */
    uint16_t getRowsCount()
    {
        return lv_table_get_row_cnt(m_this);
    }

    /**
    * Get the number of columns.
    * @param table table pointer to a Table object
    * @return number of columns.
    */
    uint16_t getColumnsCount()
    {
        return lv_table_get_col_cnt(m_this);
    }

    /**
    * Get the width of a column
    * @param table table pointer to a Table object
    * @param col_id id of the column [0 .. LV_TABLE_COL_MAX -1]
    * @return width of the column
    */
    lv_coord_t getColumnWidth(uint16_t col_id)
    {
        return lv_table_get_col_width(m_this, col_id);
    }

    /**
    * Get the text align of a cell
    * @param table pointer to a Table object
    * @param row id of the row [0 .. row_cnt -1]
    * @param col id of the column [0 .. col_cnt -1]
    * @return LV_LABEL_ALIGN_LEFT (default in case of error) or LV_LABEL_ALIGN_CENTER or LV_LABEL_ALIGN_RIGHT
    */
    lv_label_align_t getCellAlign(uint16_t row, uint16_t col)
    {
        return lv_table_get_cell_align(m_this , row, col);
    }

    /**
    * Get the type of a cell
    * @param table pointer to a Table object
    * @param row id of the row [0 .. row_cnt -1]
    * @param col id of the column [0 .. col_cnt -1]
    * @return 1,2,3 or 4
    */
    lv_label_align_t getCellType(uint16_t row, uint16_t col)
    {
        return lv_table_get_cell_type(m_this, row, col);
    }


    /**
    * Get the crop property of a cell
    * @param table pointer to a Table object
    * @param row id of the row [0 .. row_cnt -1]
    * @param col id of the column [0 .. col_cnt -1]
    * @return true: text crop enabled; false: disabled
    */
    lv_label_align_t getCellCrop(uint16_t row, uint16_t col)
    {
        return lv_table_get_cell_crop(m_this, row, col);
    }

    /**
    * Get the cell merge attribute.
    * @param table table pointer to a Table object
    * @param row id of the row [0 .. row_cnt -1]
    * @param col id of the column [0 .. col_cnt -1]
    * @return true: merge right; false: don't merge right
    */
    bool getCellMergeRight(uint16_t row, uint16_t col)
    {
        return lv_table_get_cell_merge_right(m_this,  row, col);
    }

    /**
    * Get style of a table.
    * @param table pointer to table object
    * @param type which style should be get
    * @return style pointer to the style
    */
    lv_style_t * getStyle( lv_table_style_t type)
    {
        return lv_table_get_style(m_this, type);
    }
};

#endif // LVTABLE_H

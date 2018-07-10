#ifndef VIEW_FACTORY_H
#define VIEW_FACTORY_H

#include <memory>

#include "component/view/CompositeView.h"
#include "component/view/DialogView.h"

class BookmarkView;
class CodeView;
class ErrorView;
class GraphView;
class MainView;
class RefreshView;
class ScreenSearchView;
class SearchView;
class StatusBarView;
class StatusView;
class StorageAccess;
class TabbedView;
class TooltipView;
class UndoRedoView;
class ViewLayout;

class ViewFactory
{
public:
	ViewFactory();
	virtual ~ViewFactory() = default;

	virtual std::shared_ptr<MainView> createMainView() const = 0;
	virtual std::shared_ptr<CompositeView> createCompositeView(
			ViewLayout* viewLayout, CompositeView::CompositeDirection direction, const std::string& name) const = 0;
	virtual std::shared_ptr<TabbedView> createTabbedView(ViewLayout* viewLayout, const std::string& name) const = 0;

	virtual std::shared_ptr<BookmarkView> createBookmarkView(ViewLayout* viewLayout) const = 0;
	virtual std::shared_ptr<CodeView> createCodeView(ViewLayout* viewLayout) const = 0;
	virtual std::shared_ptr<ErrorView> createErrorView(ViewLayout* viewLayout) const = 0;
	virtual std::shared_ptr<GraphView> createGraphView(ViewLayout* viewLayout) const = 0;
	virtual std::shared_ptr<RefreshView> createRefreshView(ViewLayout* viewLayout) const = 0;
	virtual std::shared_ptr<ScreenSearchView> createScreenSearchView(ViewLayout* viewLayout) const = 0;
	virtual std::shared_ptr<SearchView> createSearchView(ViewLayout* viewLayout) const = 0;
	virtual std::shared_ptr<StatusBarView> createStatusBarView(ViewLayout* viewLayout) const = 0;
	virtual std::shared_ptr<StatusView> createStatusView(ViewLayout* viewLayout) const = 0;
	virtual std::shared_ptr<TooltipView> createTooltipView(ViewLayout* viewLayout) const = 0;
	virtual std::shared_ptr<UndoRedoView> createUndoRedoView(ViewLayout* viewLayout) const = 0;

	virtual std::shared_ptr<DialogView> createDialogView(
		ViewLayout* viewLayout, DialogView::UseCase useCase, StorageAccess* storageAccess) const = 0;
};

#endif // VIEW_FACTORY_H
